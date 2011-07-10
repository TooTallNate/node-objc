#import <v8.h>
#import <node.h>
#include <dlfcn.h>
#include "dlopen.h"

using namespace node;
using namespace v8;

namespace node_objc {

  v8::Handle<Value> node_dlopen (const Arguments& args) {
    
  }

  void dlopenInit (v8::Handle<v8::Object> target) {
    HandleScope scope;
    NODE_SET_METHOD(target, "dlopen", node_dlopen);
  }

} // namespace node_objc
