#import <Foundation/NSException.h>
#import <node.h>
#import <v8.h>

namespace node_objc {

  v8::Handle<v8::Value> NSExceptionToV8Error (NSException *);

} // namespace node_objc
