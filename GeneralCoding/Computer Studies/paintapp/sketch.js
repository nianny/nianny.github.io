//let a = [];
let arr = [];
let redo = [];
let free = true;
let mainc;
let strokew;
let alpha;
let backgroundcolour = 250;
let filled = false;
let type;


function updatecurrent(){
  if (type == 'Normal'){
    current = new freehand();
  }
  else if (type == 'rainbow'){
    current = new rainbow();
  }
}

class rainbow{
  constructor(){
    //super();
    this.actions = [];
    this.thick=strokew;
    this.opacit5y=alpha;
  }

  instruct(){
    
    strokeWeight(this.thick);
    
    beginShape();
    for (let p=0; p<this.actions.length; p++){
      vertex(this.actions[p][0], this.actions[p][1]);
    }
    endShape();
  }
}


class clear {
  constructor(){

  }

  instruct(){
    background(backgroundcolour);
  }
}


class freehand {
  constructor(){
    this.actions = [];
    this.colour=mainc;
    this.thick=strokew;
    this.opacity = alpha;
    
  }

  instruct(){
    this.colour.setAlpha(this.opacity);
    stroke(this.colour);
    strokeWeight(this.thick);
    
    beginShape();
    for (let p=0; p<this.actions.length; p++){
      vertex(this.actions[p][0], this.actions[p][1]);
    }
    endShape();
    
    // for (let p=1; i<this.actions.length; p++){
    //   line(this.actions[p-1][0], this.actions[p-1][1]. this.actions[p][0], this.actions[p][1])
    // }
  }
}

function setup() {
  document.querySelector("#setalpha").innerText="newValue";

  strokeJoin(ROUND);
  mainc= color(document.getElementById("colourpicka").value);
  strokew = document.getElementById("strokewidth").value;
  alpha = map(document.getElementById("setalpha").value,0,100,0,255);
  type = document.getElementById("chooseInput").value;
  //mainc.setAlpha(alpha);
  console.log(mainc);
  cnv=createCanvas(400, 400);
  noFill();
  if (free){
    updatecurrent();
  }
  cursor(CROSS);
  //current.colour = mainc;
}

function randomC(){
  colorMode(HSB);
  mainc = color(floor(random(0,255)), 150, 255)
  colorMode(RGB);
}

function saveCall(){
  saveCanvas(cnv, 'img','jpg');
}

function updateColour(){
  mainc=color(document.getElementById("colourpicka").value);
}

function updateStrokeWidth(){
  strokew = document.getElementById("strokewidth").value;
}

function updateAlpha(){
  alpha = map(document.getElementById("setalpha").value,0,100,0,255);
  //mainc.setAlpha(alpha);
}

function changeInput(){
  type = document.getElementById("chooseInput").value;
  console.log(type)
  mouseIsPressed = false;
  if (type == "Normal"){
    arr.push(current);
    updatecurrent();
    console.log("Changed");
  }
}

function eraser(){
  mainc = color(backgroundcolour)
}

function CLEARSCREEN(){
  arr.push(current);
  current = new clear();
  arr.push(current);
  updatecurrent();
}

function UNDO(){
  //console.log("undo");
  redo.push(arr[arr.length-1]);
  arr.pop();
}

function REDO(){
  if (redo.length > 0){
    arr.push(redo[redo.length-1]);
    redo.pop();
  }
  else{
    console.log("Nothing to redo");
  }
}

function draw() {
  //arr.pop();
  background(backgroundcolour);
  if (free){
    if (mouseIsPressed == true){
      filled = true;
      current.actions.push([mouseX, mouseY]);
    }

    else if (mouseY >= 0 && filled){
      filled = false;
      arr.push(current);
      updatecurrent();
      redo = [];
    }

    for (let i=0; i<arr.length; i++){
      arr[i].instruct();
    }
    current.instruct();
  }
  //let a = [];


  // if (mouseIsPressed == true){
  //   b[b.length-1].push([mouseX, mouseY]);

  // }
  // else {
  //   b.push([]);
  // }
  // for (let p=0; p<b.length; p++){
  //   beginShape();
  //   for (let i=0; i<b[p].length; i++){
  //     vertex(b[p][i][0], b[p][i][1]);
  //   }
  //   endShape();
  // }
}
document.onkeydown = function (e) {
        return false;
} //blocks system 
function keyPressed(){
  //if (keyIsDown(ControlLeft)){
  if (keyIsDown(17) && keyIsDown(72)){
    console.log("Help requested")
    window.open("help.txt")
  }
}


//https://www.javascripttutorial.net/javascript-dom/javascript-checkbox/