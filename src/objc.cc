#include <v8.h>
#include <node.h>
#include <objc/objc.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include "IdWrap.h"
#include "SelectorWrap.h"
#include "objc.h"

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
    v8::Local<v8::Object> wrap = id_constructor_template->GetFunction()->NewInstance();
    IdWrap *idWrap = ObjectWrap::Unwrap<IdWrap>(wrap);
    idWrap->ref = c;
    return scope.Close(wrap);
  }

  v8::Handle<Value> node_objc_msgSend (const Arguments& args) {
    HandleScope scope;
    IdWrap *idWrap = ObjectWrap::Unwrap<IdWrap>(args[0]->ToObject());
    SelectorWrap *selWrap = ObjectWrap::Unwrap<SelectorWrap>(args[1]->ToObject());
    id ref = idWrap->ref;
    SEL sel = selWrap->sel;
    id rtn = objc_msgSend(ref, sel);

    v8::Local<v8::Object> wrap = id_constructor_template->GetFunction()->NewInstance();
    IdWrap *rtnWrap = ObjectWrap::Unwrap<IdWrap>(wrap);
    rtnWrap->ref = rtn;
    return scope.Close(wrap);
  }

  v8::Handle<Value> node_sel_registerName (const Arguments& args) {
    HandleScope scope;
    String::Utf8Value selStr(args[0]->ToString());
    SEL sel = sel_registerName(*selStr);
    if (!sel) {
      return Null();
    }
    Local<Object> wrap = sel_constructor_template->GetFunction()->NewInstance();
    SelectorWrap *selWrap = ObjectWrap::Unwrap<SelectorWrap>(wrap);
    selWrap->sel = sel;
    return scope.Close(wrap);
  }

  v8::Handle<Value> node_NSLog (const Arguments& args) {
    HandleScope scope;

    IdWrap *idWrap = ObjectWrap::Unwrap<IdWrap>(args[0]->ToObject());
    NSLog(@"%@", idWrap->ref);
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
