#include <v8.h>
#include <node.h>
#include "IdWrap.h"
#include "dlopen.h"
#include "objc.h"

using namespace node;
using namespace v8;

namespace node_objc {

extern "C" void init(v8::Handle<Object> target) {
  HandleScope scope;
  IdWrap::Init(target);
  dlopenInit(target);
  objcInit(target);
}

} // namespace node_objc
