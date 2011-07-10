#import <Foundation/Foundation.h>
#import <node.h>
#import <v8.h>

namespace node_objc {

  v8::Handle<v8::Value> NSExceptionToV8Error (NSException *);

  v8::Handle<v8::Object> NSDictionaryToV8Object (NSDictionary *d);

} // namespace node_objc
