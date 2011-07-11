def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")

  if conf.check_cxx(msg="Checking for header file <ffi/ffi.h>", fragment="""
    #include <ffi/ffi.h>
    int main() {
      return 0;
    }
  """):
    conf.env.append_value('CXXFLAGS', '-DHAVE_FFI_DIR=1')


def build(bld):
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.cxxflags = ["-g", "-D_FILE_OFFSET_BITS=64", "-D_LARGEFILE_SOURCE", "-Wall", "-ObjC++", "-fobjc-sjlj-exceptions"]
  obj.ldflags = ["-mmacosx-version-min=10.5", "-lobjc", "-lffi"]
  obj.framework = ["Foundation"]
  obj.target = "bindings"
  obj.source = ["src/bindings.cc", "src/dlopen.cc", "src/objc.cc", "src/IdWrap.cc",
       "src/SelectorWrap.cc", "src/JsWrap.cc", "src/casts.cc", "src/helpers.cc"]
