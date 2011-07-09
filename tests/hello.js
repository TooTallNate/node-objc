var objc = require('objc');

// import the Foundation framework
objc.import('Foundation');

// create an NSString from a JavaScript String
var NSString = objc.objc_getClass('NSString')
  , stringSelector = objc.sel_registerName('stringWithUTF8String:');
  , helloStr   = 'Hello World!'
  , helloNsStr = objc.objc_msgSend(NSString, stringSelector, helloStr)

// log the string with NSLog
obj.NSLog(helloNsStr);
