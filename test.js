var objc = require('./')
  , NSMutableArray = objc.objc_getClass('NSMutableArray')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')

var a = objc.objc_msgSend(NSMutableArray, alloc);
a = objc.objc_msgSend(a, init);

objc.NSLog(a);
