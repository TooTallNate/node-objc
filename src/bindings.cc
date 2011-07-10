#import <v8.h>
#import <node.h>
#include "dlopen.h"

using namespace node;
using namespace v8;

namespace node_objc {

extern "C" void init(v8::Handle<Object> target) {
  HandleScope scope;
  dlopenInit(target);
}

} // namespace node_objc
