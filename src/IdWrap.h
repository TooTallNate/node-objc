#include <node.h>
#include <v8.h>

namespace node_objc {

// `IdWrap` is a node ObjectWrap that wraps up an ObjC `id`. This allows
// arbitrary ObjectiveC objects to be passed around the V8 environment.

extern v8::Persistent<v8::FunctionTemplate> id_constructor_template;

class IdWrap : public node::ObjectWrap {
public:

  IdWrap();
  ~IdWrap();

  id ref;

  static void Init(v8::Handle<v8::Object>);

  static v8::Handle<v8::Value> New(const v8::Arguments&);

  // 'toString()' override
  static v8::Handle<v8::Value> ToString(const v8::Arguments&);

}; // class IdWrap

} // namespace node_objc
