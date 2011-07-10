var bindings = require('./build/default/bindings.node')
  , fs = require('fs')

['objc_getClass', 'objc_msgSend'].forEach(function (func) {
  exports[func] = bindings[name];
});

exports.resolve = function resolve (framework) {

}

exports.import = function import (framework) {
  return bindings.dlopen(exports.resolve(framework));
}
