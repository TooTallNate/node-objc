var objc = require('../')
  , NSAutoreleasePool = objc.objc_getClass('NSAutoreleasePool')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')
  , bad = objc.sel_registerName('bad')

var pool = objc.objc_msgSend(NSAutoreleasePool, alloc);
pool = objc.objc_msgSend(pool, init);

objc.objc_msgSend(pool, objc.sel_registerName('drain'));
try {
  objc.objc_msgSend(pool, bad);
} catch (e) {
  console.error(e.name);
  console.error(e.message);
  console.error(e.info);
  console.error(e.stack);
}

//objc.objc_msgSend(pool, objc.sel_registerName('drain'));
