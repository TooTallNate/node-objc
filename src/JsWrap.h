#import <Foundation/NSObject.h>
#include <v8.h>

@interface JsWrap: NSObject {
@public
  v8::Persistent<v8::Value> ref;
}
@end

