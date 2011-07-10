#include <v8.h>
#include <node.h>
#include <dlfcn.h>
#include "dlopen.h"

using namespace node;
using namespace v8;

namespace node_objc {

  v8::Handle<Value> node_dlopen (const Arguments& args) {
    HandleScope scope;

    // Ensure a String was given
    if (args.Length() < 1 || !args[0]->IsString()) {
      return ThrowException(Exception::TypeError(String::New("A 'String' argument is required!")));
    }
    String::Utf8Value frameworkStr(args[0]->ToString());
    // Load the framework
    void *sdl_library = dlopen(*frameworkStr, RTLD_LAZY);
    if (sdl_library == NULL) {
      return v8::ThrowException(v8::Exception::Error(v8::String::New(dlerror())));
    }
    return Undefined();
  }

  // INIT function
  void dlopenInit (v8::Handle<v8::Object> target) {
    HandleScope scope;
    NODE_SET_METHOD(target, "dlopen", node_dlopen);
  }

} // namespace node_objc
