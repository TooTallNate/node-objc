var assert = require('assert')
  , objc = require('../')

assert.throws(function () {
  objc.dlopen();
});
assert.throws(function () {
  objc.dlopen({});
});
assert.throws(function () {
  objc.dlopen('BAD');
});
