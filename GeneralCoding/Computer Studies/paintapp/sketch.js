/*
Basically how does this code work. It might be a mess because I didn't reallty organise the functions and things.

The entire "route" to get to the current stage in stored in an array and printed out every frane. 
The form of the "actions" are stored in a class, which has an "instruct()" methods to print out its individual things. 
THis is mainly because different types of pens and things have vastly different ways of drawing out the things, and I thought it would be easier to just iterate thorugh the entire array and call a method of that object.

One of the most important functions in this code is the "updateCurrent()" function. This is called when any settings from html are changed or if a new object is required (e.g. the mouse is no longer pressed). 
It will create an object called "current" based on the classes - it knows which one to choose from the html dropdown.
*/



//let a = [];
let arr = [];  //arr that stores all the things to be printed out when the sketch refreshes
let redo = []; //used to stores things that have been undoed (not printed), pushed when undo button pressed, popped when redo button pressed, and cleared when any changes are made
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
  else if (type = 'highlighter'){
    current = new highlighter();
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
    this.set = random([2,-2]) 
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
      
      //this.colour.setAlpha(this.opacity);
      stroke(this.colour)
      line(this.actions[p-1][0], this.actions[p-1][1], this.actions[p][0], this.actions[p][1])
    }
    //console.log(this.colour);
    
    colorMode(RGB);
  }

  detect(){
    if (mouseIsPressed == true && mouseX >= -20){
      filled = true;
      this.actions.push([mouseX, mouseY]);
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
    this.instruct();
  }

  present(){
    this.sample = createGraphics(width/20, height/20);
    this.sample.point(this.sample.width/2, this.sample.height/2);

    image(this.sample, 0,0);
  }
}


class clear {
  constructor(){

  }

  instruct(){
    background(backgroundcolour);
  }
}

class highlighter {
  constructor(){
    this.actions = [];
    this.colour = mainc;
    this.thick = strokew;
    this.change = createVector(-(this.thick*tan(60  )), -(this.thick))
  }

  instruct(){
    noStroke();
    //stroke(this.colour);
    fill(this.colour);
    

    for (let p=1; p<this.actions.length-1; p++){
      beginShape();
      vertex(this.actions[p].x+this.change.x, this.actions[p].y + this.change.y);
      vertex(this.actions[p].x, this.actions[p].y);
      vertex(this.actions[p+1].x, this.actions[p+1].y);
      vertex(this.actions[p+1].x+this.change.x, this.actions[p+1].y+this.change.y);
      endShape(CLOSE);

      beginShape();
      vertex(this.actions[p].x+this.change.x-0.1, this.actions[p].y + this.change.y);
      vertex(this.actions[p].x-0.1, this.actions[p].y);
      vertex(this.actions[p].x+0.1, this.actions[p].y);
      vertex(this.actions[p].x+this.change.x+0.1, this.actions[p].y+this.change.y);
      endShape(CLOSE);
    }

    noFill();
  }

  detect(){
    if (mouseIsPressed == true && mouseX >= -20){
      filled = true;
      let currentpos = createVector(mouseX, mouseY)
      this.actions.push(currentpos);
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
    this.instruct();
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

  detect(){
    if (mouseIsPressed == true && mouseX >= -20){
      filled = true;
      this.actions.push([mouseX, mouseY]);
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
    this.instruct();
  }

  present(){
    this.sample = createGraphics(width/20, height/20);
    this.sample.stroke(this.colour);
    this.sample.strokeWeight(this.thick);
    this.sample.fill(0);
    this.sample.rect(0,0,this.sample.width, this.sample.height);
    this.sample.point(this.sample.width/2, this.sample.height/2);

    image(this.sample, 0,0);
    //console.log("Hallo")
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
  cnv=createCanvas(windowWidth/2, windowHeight);
  var x = (windowWidth - width) / 2;
  var y = (windowHeight - height) / 2;
  cnv.position(x, y);
  cnv.style('display', 'block');
  noFill();
  updatecurrent();
  
  cursor(CROSS);


  pg = createGraphics(width/20, height/20);



  //current.colour = mainc;
}

function randomC(){

  let r = floor(random(50,200));
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
  updatecurrent();
}

function windowResized() {
  resizeCanvas(windowWidth/2, windowHeight);
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
  arr.push(current);
  updatecurrent();
  console.log("Changed");
  
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
  current.detect();

  //current.present();

  pg.background(0);
  image(pg,width/2,height/2);
  
  //drawLogo();

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
    updatecurrent();

  }
}


//https://www.javascripttutorial.net/javascript-dom/javascript-checkbox/