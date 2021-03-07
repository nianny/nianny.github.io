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
  else if (type == 'Eraser'){
    current = new freehand(true);
  }
  
}

class rainbow{
  constructor(){
    //super();
    this.actions = [];
    this.colours = [];
    this.thick=strokew;
    this.opacity=alpha;
    colorMode(HSB);
    this.value = int(random(255));
    this.colour=color(this.value,150,200);
    colorMode(RGB);
    console.log("Create new node")
    //console.log(this.value);
    this.set = random([1,-1]) 
  }

  instruct(){
    this.increase = this.set;
    this.colours[0] = this.value;
    for (let p=1; p<this.actions.length; p++){
      this.colours[p] = this.colours[p-1]+this.increase;
      if (this.colours[p] >= 255 || this.colours[p] <= 0){
        this.increase = (-1)*this.increase;
      }
    }
    colorMode(HSB);
    
    strokeWeight(this.thick);
    //console.log(this.value);
    
    // beginShape();
    // for (let p=0; p<this.actions.length; p++){
    //   this.colour = color(this.colours[p], 150, 200, this.opacity);
    //   stroke(this.colour);
    //   // this.colour= color(this.value, 150,200);
    //   // this.colour.setAlpha(this.opacity);
    //   // stroke(this.colour);
    //   vertex(this.actions[p][0], this.actions[p][1]);
    //   this.value += 1;
    //   console.log(this.colours[p]);
    //   // if (this.value >= 255){
    //   //   this.value = 0;
    //   // }  
    // }
    // endShape();

    for (let p=1; p<this.actions.length; p++){
      this.colour = color(this.colours[p],100,150);
      this.colour.setAlpha(this.opacity);
      stroke(this.colour)
      line(this.actions[p-1][0], this.actions[p-1][1], this.actions[p][0], this.actions[p][1])
    }
    
    colorMode(RGB);
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
  constructor(eraser=false){
    this.actions = [];
    this.colour=mainc;
    this.thick=strokew;
    this.opacity = alpha;
    this.eraser = eraser;
    
  }

  instruct(){
    if (!this.eraser){
      this.colour.setAlpha(this.opacity);
      stroke(this.colour);
    }
    else{
      stroke(backgroundcolour);
    }
    strokeWeight(this.thick);
    
    beginShape();
    for (let p=0; p<this.actions.length; p++){
      vertex(this.actions[p][0], this.actions[p][1]);
    }
    endShape();
    
    // for (let p=1; p<this.actions.length; p++){
    //   line(this.actions[p-1][0], this.actions[p-1][1], this.actions[p][0], this.actions[p][1])
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
  cnv=createCanvas(windowWidth/4*3, windowHeight);
  var x = (windowWidth - width) / 4*3.9;
  var y = (windowHeight - height) / 2;
  cnv.position(x, y);
  cnv.style('display', 'block');
  noFill();
  if (free){
    updatecurrent();
  }
  cursor(CROSS);
  //current.colour = mainc;
}

function randomC(){

  let r = floor(random(0,255));
  let g = 150;
  let b = 255;
  let c = color(r,g,b);
  let hx = "#" + hex(r,2) + hex(g,2) + hex(b,2);

  colorMode(HSB);
  mainc = color(floor(random(0,255)), 150, 255)
  colorMode(RGB);
  document.getElementById("colourpicka").value = '#FFFFFF';

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

function windowResized() {
  resizeCanvas(windowWidth/4*3, windowHeight);
  centerCanvas();
}

function centerCanvas() {
  var x = (windowWidth - width) / 4*2.5;
  var y = (windowHeight - height) / 2;
  cnv.position(x, y);
}



function updateAlpha(){
  alpha = map(document.getElementById("setalpha").value,0,100,0,255);
  console.log(alpha);
  //mainc.setAlpha(alpha);
}

function changeInput(){
  type = document.getElementById("chooseInput").value;
  console.log(type)
  mouseIsPressed = false;
  if (type == "Normal" || type == "Eraser"){
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
function drawLogo(){
  textFont('Potta One');
  textSize(20);
  textAlign(CENTER);
  textStyle(NORMAL);
  text("Nianny Paint", width/2, height/2);
}
function draw() {
  //arr.pop();
  background(backgroundcolour);
  //drawLogo();
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
    window.open("help.html");
  }
  else if (keyIsDown(17) && keyIsDown(82)){
    document.getElementById("setalpha").value = 100;
    document.getElementById("strokewidth").value = 5;
    document.getElementById("colourpicka").value = '#000000'
    document.getElementById("chooseInput").value = "Normal";
    alpha = 255;
    strokew =5;
    mainc=color('#000000')
    type = "Normal"

  }
}


//https://www.javascripttutorial.net/javascript-dom/javascript-checkbox/