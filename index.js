var bindings = module.exports = require('./build/default/bindings.node')
  , fs = require('fs')

bindings.IdWrap.prototype.inspect = function () {
  return "'" + this.toString() + "'";
}
