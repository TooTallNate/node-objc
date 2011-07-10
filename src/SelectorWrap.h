#include <Foundation/Foundation.h>
#include <node.h>
#include <v8.h>

namespace node_objc {

// `SelectorWrap` is a node ObjectWrap that wraps up an ObjC `SEL`.

extern v8::Persistent<v8::FunctionTemplate> sel_constructor_template;

class SelectorWrap : public node::ObjectWrap {
public:

  SelectorWrap();
  ~SelectorWrap();

  SEL sel;

  static void Init(v8::Handle<v8::Object>);

  static v8::Handle<v8::Value> New(const v8::Arguments&);

  // 'toString()' override
  static v8::Handle<v8::Value> ToString(const v8::Arguments&);

}; // class SelectorWrap

} // namespace node_objc
