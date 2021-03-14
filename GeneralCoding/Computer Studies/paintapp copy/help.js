function preload(){
    result = loadStrings('help.txt'); //loads from
}

function setup(){

}

function draw(){

}

function downloadhelp(){
    console.log("Download")
    saveStrings(result, "Help and instructions.txt")
}

function keyPressed(){
    //if (keyIsDown(ControlLeft)){
    if (keyIsDown(17) && (keyIsDown(68) || keyIsDown(72))){
        downloadhelp();
    }
  }