var objc = require('../');

// create an NSString from a JavaScript String
var helloStr   = 'Hello World!'
  , helloNsStr = objc.NSString(helloStr)

console.log(helloNsStr);
