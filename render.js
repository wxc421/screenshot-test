

// document.getElementById("screenshot").addEventListener("click", function(){
//     addon.hello()
// });

document.getElementById("screenshot").addEventListener("click", async function(){
    const response = await window.screentshot.run()
});
