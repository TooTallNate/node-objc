var objc = require('../')
  , abi = objc.sel_registerName('applicationWithBundleIdentifier:')

var NSAutoreleasePool = objc.objc_getClass('NSAutoreleasePool')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')
  , pool = objc.objc_msgSend(objc.objc_msgSend(NSAutoreleasePool, alloc), init)

objc.dlopen("/System/Library/Frameworks/ScriptingBridge.framework/Versions/Current/ScriptingBridge");

var SBApplication = objc.objc_getClass('SBApplication')
  , iTunes = objc.objc_msgSend(SBApplication, abi, objc.NSString("com.apple.iTunes"));

console.log(iTunes);

var currentTrackSel = objc.sel_registerName('currentTrack')
  , currentTrack = objc.objc_msgSend(iTunes, currentTrackSel)

console.log(currentTrack);

var nameSel = objc.sel_registerName('name')
  , name = objc.objc_msgSend(currentTrack, nameSel)

console.log(name);
