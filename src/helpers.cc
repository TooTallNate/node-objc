#import <Foundation/Foundation.h>
#include <v8.h>
#include <node.h>
#include "helpers.h"

using namespace node;
using namespace v8;

namespace node_objc {

  static Persistent<String> ERR_NAME_SYMBOL = NODE_PSYMBOL("name");
  static Persistent<String> ERR_INFO_SYMBOL = NODE_PSYMBOL("info");

  v8::Handle<Value> NSExceptionToV8Error (NSException *e) {
    HandleScope scope;
    NSString *name = [e name];
    NSString *reason = [e reason];
    v8::Handle<Value> error = v8::Exception::Error(v8::String::New([reason UTF8String]));
    v8::Handle<Object> errObj = error->ToObject();
    errObj->Set(ERR_NAME_SYMBOL, String::New([name UTF8String]));
    NSDictionary *info = [e userInfo];
    if (info) {
      errObj->Set(ERR_INFO_SYMBOL, NSDictionaryToV8Object(info));
    }
    return scope.Close(error);
  }

  v8::Handle<Object> NSDictionaryToV8Object (NSDictionary *d) {
    HandleScope scope;
    v8::Handle<Object> rtn = Object::New();
    NSEnumerator *enumerator = [d keyEnumerator];
    id key;
    id value;
    while ((key = [enumerator nextObject])) {
      value = [d objectForKey: key];
      //rtn->Set(String::New([[id description] UTF8String]), WrapId(value));
    }
    return scope.Close(rtn);
  }

} // namespace node_objc
