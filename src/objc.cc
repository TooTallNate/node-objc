#include <v8.h>
#include <node.h>
#include <objc/runtime.h>
#include "IdWrap.h"
#include "objc.h"

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

  // INIT function
  void objcInit (v8::Handle<v8::Object> target) {
    HandleScope scope;
    NODE_SET_METHOD(target, "objc_getClass", node_objc_getClass);
  }

} // namespace node_objc
