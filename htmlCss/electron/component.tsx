// for icp communication
const { ipcRenderer  } = window.require('electron');


// In class component

// to send the message for channel (first)
ipcRenderer.send("first", {
			"sender":"rendere"
})

// to receive message from the channel (first)
ipcRenderer.on("first", (event, args): void => {
		console.log(event, args);
})