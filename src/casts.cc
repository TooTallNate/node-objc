#import <Foundation/Foundation.h>
#include <node.h>
#include <v8.h>
#include "helpers.h"

using namespace v8;
using namespace node;

namespace node_objc {

  // Cast a JavaScript "String" to an "NSString"
  v8::Handle<Value> Cast_NSString (const Arguments& args) {
    HandleScope scope;
    String::Utf8Value val(args[0]->ToString());
    NSString *rtn = [NSString stringWithUTF8String: *val];
    v8::Handle<Object> rtnWrap = WrapId(rtn);
    return scope.Close(rtnWrap);
  }

  // Cast a JavaScript "Number" to an "NSNumber"
  v8::Handle<Value> Cast_NSNumber (const Arguments& args) {
    HandleScope scope;
    double val = args[0]->NumberValue();
    NSNumber *rtn = [NSNumber numberWithDouble: val];
    v8::Handle<Object> rtnWrap = WrapId(rtn);
    return scope.Close(rtnWrap);
  }

  void castsInit(v8::Handle<v8::Object> target) {
    HandleScope scope;
    NODE_SET_METHOD(target, "NSString", Cast_NSString);
    NODE_SET_METHOD(target, "NSNumber", Cast_NSNumber);
  }

} // namespace node_objc
