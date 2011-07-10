var bindings = module.exports = require('./build/default/bindings.node')
  , inspect = require('util').inspect
  , fs = require('fs')

bindings.IdWrap.prototype.inspect = bindings.SelectorWrap.prototype.inspect = function () {
  return inspect(this.toString());
}
