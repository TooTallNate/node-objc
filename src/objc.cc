#include <v8.h>
#include <node.h>
#include <objc/objc.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include <ffi/ffi.h>
#include "objc.h"
#include "helpers.h"

// Debug
#import <Foundation/Foundation.h>
#include <stdio.h>

using namespace node;
using namespace v8;

namespace node_objc {

  v8::Handle<Value> node_objc_getClass (const Arguments& args) {
    HandleScope scope;
    String::Utf8Value classStr(args[0]->ToString());
    // get the requested Class
    Class c = objc_getClass(*classStr);
    // if null was returned, then return JavaScript null
    if (!c) {
      return Null();
    }
    return scope.Close(WrapId(c));
  }

  // For debugging libffi...
  id fake_msgSend (id ref, SEL sel, ...) {
    int j;
    va_list ap;
    va_start(ap, sel); //Requires the last fixed parameter (to get the address)
    for(j=0; j<1; j++) {
      const char * param = va_arg(ap, const char *); //Requires the type to cast to. Increments ap to the next argument.
      NSLog(@"string: %s", param);
    }
    va_end(ap);
    return ref;
  }

  v8::Handle<Value> node_objc_msgSend (const Arguments& args) {
    HandleScope scope;

    ffi_cif cif;
    int argv = args.Length();
    ffi_type  **arg_types;
    void      **arg_values;
    ffi_status status;
    id result;

    arg_types  = (ffi_type **) malloc(argv*sizeof(ffi_type *));
    arg_values = (void **) malloc(argv*sizeof(void *));

    arg_types[0] = &ffi_type_pointer;
    arg_types[1] = &ffi_type_pointer;

    id ref = UnwrapId(args[0]->ToObject());
    SEL sel = UnwrapSel(args[1]->ToObject());
    arg_values[0] = &ref;
    arg_values[1] = &sel;

    Local<Value> val;
    for (int i=2; i < argv; i++) {
      val = args[i];
      arg_types[i] = &ffi_type_pointer;
      if (val->IsString()) {
        String::Utf8Value strVal(val->ToObject());
        const char * cStrVal = *strVal;
        arg_values[i] = &cStrVal;
      } else {

      }
    }

    if ((status = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argv, &ffi_type_pointer, arg_types)) != FFI_OK) {
      return v8::ThrowException(v8::Exception::Error(v8::String::New("`ffi_prep_cif` failed!")));
    }

    @try {
      ffi_call(&cif, FFI_FN(objc_msgSend), &result, arg_values);
    }
    @catch (NSException *e) {
      return v8::ThrowException(NSExceptionToV8Error(e));
    }

    //NSLog(@"Length: %d", [result length]);

    v8::Handle<Object> wrap = WrapId(result);

    free(arg_types);
    free(arg_values);
    return scope.Close(wrap);
  }

  v8::Handle<Value> node_sel_registerName (const Arguments& args) {
    HandleScope scope;
    String::Utf8Value selStr(args[0]->ToString());
    SEL sel = sel_registerName(*selStr);
    if (!sel) {
      return Null();
    }
    return scope.Close(WrapSel(sel));
  }

  v8::Handle<Value> node_NSLog (const Arguments& args) {
    HandleScope scope;

    id ref = UnwrapId(args[0]->ToObject());
    NSLog(@"%@", ref);
    return Undefined();
  }

  // INIT function
  void objcInit (v8::Handle<v8::Object> target) {
    HandleScope scope;
    NODE_SET_METHOD(target, "objc_getClass", node_objc_getClass);
    NODE_SET_METHOD(target, "objc_msgSend", node_objc_msgSend);
    NODE_SET_METHOD(target, "sel_registerName", node_sel_registerName);
    NODE_SET_METHOD(target, "NSLog", node_NSLog);
  }

} // namespace node_objc
