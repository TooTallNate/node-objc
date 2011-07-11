#import <Foundation/Foundation.h>
#import "JsWrap.h"
#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

@implementation JsWrap

- (NSString *)description {
  HandleScope scope;
  Local<Object> val = self->ref->ToObject();
  Local<String> str = val->ToString();
  String::Utf8Value cStr(str);
  return [NSString stringWithUTF8String: *cStr ];
}

@end

