console.log("running background.js");

const port = chrome.runtime.connectNative("com.mynative.host");

if(port)
{
	port.onMessage.addListener(function(msg){
		console.log("message received in background.js", msg);
	});

	port.postMessage({"from" : "background.js"});
}


port.onDisconnect.addListener(function(){
	console.log("native host connection disconnected....");
});