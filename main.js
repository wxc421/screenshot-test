const { app, BrowserWindow, ipcMain } = require('electron')
const path = require('path')

const createWindow = () => {
  const win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
    //   nodeIntegration: true,
    //   contextIsolation: false,
      preload: path.join(__dirname, 'preload.js'),
    },
  })
  win.webContents.openDevTools()
  win.loadFile('index.html')
}

var addon = require('bindings')('hello')

app.whenReady().then(() => {
  ipcMain.handle('run', () => addon.hello())
  createWindow()
})
