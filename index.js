var bindings = module.exports = require('./build/default/bindings.node')
  , fs = require('fs')

bindings.resolve = function resolve (framework) {

}

bindings.import = function import (framework) {
  return bindings.dlopen(bindings.resolve(framework));
}
