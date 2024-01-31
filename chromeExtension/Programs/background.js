console.log("background.js....");

function sendMessage(message) {
	chrome.tabs.query({ active: true, currentWindow: true }, function (tabs) {
	  // Ensure that there is an active tab
	  if (tabs.length > 0) {
		chrome.tabs.sendMessage(tabs[0].id, { action: "renu", message: message });
	  } else {
		console.error("No active tab found.");
	  }
	});
  }
chrome.runtime.onMessage.addListener(
	function(request, sender, replyTo)
	{
		if(request.action === "renu")
		{
			console.log("message received on background.js: ", request.message);
			sendMessage("background.js");
		}
	}
);