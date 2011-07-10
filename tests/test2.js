var objc = require('./')

objc.dlopen('/System/Library/Frameworks/AppKit.framework/AppKit');

NSApplication = objc.objc_getClass('NSApplication');
console.log(''+NSApplication);

var sharedApplication = objc.sel_registerName('sharedApplication');
objc.objc_msgSend(NSApplication, sharedApplication);
