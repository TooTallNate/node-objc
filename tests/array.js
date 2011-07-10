var objc = require('../')
  , NSMutableArray = objc.objc_getClass('NSMutableArray')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')
  , addObject = objc.sel_registerName('addObject:')

// Create an NSMutableArray instance
var a = objc.objc_msgSend(NSMutableArray, alloc);
a = objc.objc_msgSend(a, init);

// Add an object to the array
objc.objc_msgSend(a, addObject, NSMutableArray);

// Make a copy of the mutable array as an immutable array
var b = objc.objc_msgSend(objc.objc_getClass('NSArray'), objc.sel_registerName('arrayWithArray:'), a);

// Add a few more objects to the mutable array
objc.objc_msgSend(a, addObject, NSMutableArray);
objc.objc_msgSend(a, addObject, objc.NSString('Hello World!'));
objc.objc_msgSend(a, addObject, objc.NSNumber(Math.random()));

// debug printout
console.log(a);
console.log(b);
