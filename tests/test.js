var objc = require('../')
  , NSMutableArray = objc.objc_getClass('NSMutableArray')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')

var a = objc.objc_msgSend(NSMutableArray, alloc);
a = objc.objc_msgSend(a, init);

objc.objc_msgSend(a, objc.sel_registerName('addObject:'), NSMutableArray);

var b = objc.objc_msgSend(objc.objc_getClass('NSArray'), objc.sel_registerName('arrayWithArray:'), a);
objc.objc_msgSend(a, objc.sel_registerName('addObject:'), NSMutableArray);

console.log(a);
