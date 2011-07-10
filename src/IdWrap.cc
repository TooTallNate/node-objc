#import <Foundation/Foundation.h>
#include "helpers.h"
#include "IdWrap.h"

using namespace node;
using namespace v8;

namespace node_objc {

static Persistent<String> ID_CLASS_SYMBOL;
Persistent<FunctionTemplate> id_constructor_template;

void IdWrap::Init(v8::Handle<Object> target) {
  HandleScope scope;

  // String Constants
  ID_CLASS_SYMBOL = NODE_PSYMBOL("IdWrap");

  // Set up the 'IdWrap' base-class constructor template
  Local<FunctionTemplate> t = FunctionTemplate::New(New);
  id_constructor_template = Persistent<FunctionTemplate>::New(t);
  id_constructor_template->SetClassName(ID_CLASS_SYMBOL);
  t->InstanceTemplate()->SetInternalFieldCount(1);

  NODE_SET_PROTOTYPE_METHOD(t, "toString", ToString);

  // Casting functions
  // NSArray to Array
  //NODE_SET_PROTOTYPE_METHOD(t, "toArray", ToArray);
  // NSNumber to Number
  //NODE_SET_PROTOTYPE_METHOD(t, "toNumber", ToNumber);
  // NSInteger to Number
  //NODE_SET_PROTOTYPE_METHOD(t, "intToNumber", IntToNumber);

  target->Set(ID_CLASS_SYMBOL, id_constructor_template->GetFunction());
}


// C++ Constructor/Destructor ////////////////////////////////////////////////
IdWrap::IdWrap() {
}

IdWrap::~IdWrap() {
}

// JavaScript Constructor/////////////////////////////////////////////////////
v8::Handle<Value> IdWrap::New(const Arguments& args) {
  HandleScope scope;
  IdWrap *idWrap = new IdWrap();
  idWrap->Wrap(args.This());
  return args.This();
}

// ToString //////////////////////////////////////////////////////////////////
v8::Handle<Value> IdWrap::ToString(const Arguments& args) {
  HandleScope scope;
  id ref = UnwrapId(args.This());
  NSString *str;
  //@try {
  if ([ref isKindOfClass: [NSString class]]) {
    str = (NSString *)ref;
  } else {
    str = [ref description];
  }
  Local<String> rtn = String::New((const char *)[str UTF8String]);
  return scope.Close(rtn);
}

} // namespace node_iTunes
