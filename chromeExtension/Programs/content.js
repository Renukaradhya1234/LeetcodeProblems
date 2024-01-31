console.log("content.js");

chrome.runtime.sendMessage({"action" : "renu",
							"message" : "This is from content.js"});

chrome.runtime.onMessage.addListener(
	function(request, sender, replyTo)
	{
		if(request.action === "renu")
		{
			console.log("message received in content.js: ", request.message);
		}
	}
);

element = document.querySelector("#name");
if(element == null)
{
	console.log("element is null...");
}
else 
{
	element.focus();
	element.text("from Extension...");
}