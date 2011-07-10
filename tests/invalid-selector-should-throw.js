var objc = require('../')
  , NSAutoreleasePool = objc.objc_getClass('NSAutoreleasePool')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')
  , bad = objc.sel_registerName('bad')

var pool = objc.objc_msgSend(NSAutoreleasePool, alloc);
pool = objc.objc_msgSend(pool, init);

console.log(pool);

try {
  objc.objc_msgSend(pool, bad);
} catch (e) {
  throw e;
}
