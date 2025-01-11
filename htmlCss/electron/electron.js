import { app, BrowserWindow } from "electron";
import path from "path"
import { fileURLToPath } from "url";

class ElectronApplication {
	constructor() {
		this.dirName = path.dirname(fileURLToPath(import.meta.url));
		this.URLPath = `file://${path.join(this.dirName, '../build/index.html')}`;
		this.StartElectron();
	}

	CreateWindow() {
		const winWindow = new BrowserWindow({
			width: 800,
			heigth: 800,
			webPreferences: {
				nodeIntegration: true,
				contextIsolation: false
			},
		})

		winWindow.loadURL(this.URLPath);
	}

	StartElectron() {
		app.whenReady()
			.then(() => {
				this.CreateWindow();
			})
	}
}

new ElectronApplication();