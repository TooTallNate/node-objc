#import <Foundation/Foundation.h>
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
    Class c = objc_getClass(*classStr);
    //Local<v8::Object> wrap = id_constructor_template->GetFunction->NewInstance();
    NSLog(@"%@", c);
    return Undefined();
  }

  // INIT function
  void objcInit (v8::Handle<v8::Object> target) {
    HandleScope scope;
    NODE_SET_METHOD(target, "objc_getClass", node_objc_getClass);
  }

} // namespace node_objc
