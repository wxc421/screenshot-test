const { contextBridge, ipcRenderer } = require('electron')



contextBridge.exposeInMainWorld('screentshot', {
    run: () => ipcRenderer.invoke('run'),
  })