#import <Foundation/Foundation.h>
#import <node.h>
#import <v8.h>

namespace node_objc {

  v8::Handle<v8::Object> WrapId(id);

  v8::Handle<v8::Object> WrapSel(SEL);

  id UnwrapId(v8::Handle<v8::Object>);

  SEL UnwrapSel(v8::Handle<v8::Object>);

  v8::Handle<v8::Value> NSExceptionToV8Error (NSException *);

  v8::Handle<v8::Object> NSDictionaryToV8Object (NSDictionary *d);

} // namespace node_objc
