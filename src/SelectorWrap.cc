#include "SelectorWrap.h"

using namespace node;
using namespace v8;

namespace node_objc {

static Persistent<String> SEL_CLASS_SYMBOL;
Persistent<FunctionTemplate> sel_constructor_template;

void SelectorWrap::Init(v8::Handle<Object> target) {
  HandleScope scope;

  // String Constants
  SEL_CLASS_SYMBOL = NODE_PSYMBOL("SelectorWrap");

  // Set up the 'SelectorWrap' base-class constructor template
  Local<FunctionTemplate> t = FunctionTemplate::New(New);
  sel_constructor_template = Persistent<FunctionTemplate>::New(t);
  sel_constructor_template->SetClassName(SEL_CLASS_SYMBOL);
  t->InstanceTemplate()->SetInternalFieldCount(1);

  NODE_SET_PROTOTYPE_METHOD(t, "toString", ToString);

  target->Set(SEL_CLASS_SYMBOL, sel_constructor_template->GetFunction());
}


// C++ Constructor/Destructor ////////////////////////////////////////////////
SelectorWrap::SelectorWrap() {
}

SelectorWrap::~SelectorWrap() {
}

// JavaScript Constructor/////////////////////////////////////////////////////
v8::Handle<Value> SelectorWrap::New(const Arguments& args) {
  HandleScope scope;
  SelectorWrap *selWrap = new SelectorWrap();
  selWrap->Wrap(args.This());
  return args.This();
}

// ToString //////////////////////////////////////////////////////////////////
v8::Handle<Value> SelectorWrap::ToString(const Arguments& args) {
  HandleScope scope;
  SelectorWrap *item = ObjectWrap::Unwrap<SelectorWrap>(args.This());
  Local<String> str = String::New((const char *)sel_getName(item->sel));
  return scope.Close(str);
}

} // namespace node_iTunes
