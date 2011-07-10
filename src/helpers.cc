#import <Foundation/Foundation.h>
#include <v8.h>
#include <node.h>
#include "helpers.h"

using namespace node;
using namespace v8;

namespace node_objc {

  v8::Handle<Value> NSExceptionToV8Error (NSException *e) {
    HandleScope scope;
    NSString *name = [e name];
    NSString *reason = [e reason];
    NSString *message = [NSString stringWithFormat: @"%@: %@", name, reason];
    v8::Handle<Value> error = v8::Exception::Error(v8::String::New([message UTF8String]));
    return scope.Close(error);
  }

} // namespace node_objc
