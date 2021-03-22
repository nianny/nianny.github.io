/*
Basically how does this code work. It might be a mess because I didn't reallty organise the functions and things.

The entire "route" to get to the current stage in stored in an array and printed out every frane. 
The form of the "actions" are stored in a class, which has an "instruct()" methods to print out its individual things. 
THis is mainly because different types of pens and things have vastly different ways of drawing out the things, and I thought it would be easier to just iterate thorugh the entire array and call a method of that object.

One of the most important functions in this code is the "updateCurrent()" function. 
This is called when any settings from html are changed or if a new object is required (e.g. the mouse is no longer pressed). 
It will create an object called "current" based on the classes - it knows which one to choose from the html dropdown.

The last thing is that every "draw" function, a checker is made to check if the current position and things should be stored or even if a new node should be created.
This was implemented because there was the possibility of having things with differect detection types, such as shapes which is planned to require two mouse clicks/mouse dragged.

Note: 
- all other testing comments (e.g. alternative testing, console.log) were removed
*/



//let a = [];
let arr = [];  //arr that stores all the things to be printed out when the sketch refreshes
let redo = []; //used to stores things that have been undoed (not printed), pushed when undo button pressed, popped when redo button pressed, and cleared when any changes are made
let mainc; //colour
let strokew; //stroke weight
let alpha; //opacity
let backgroundcolour = 250; //background colour (to make it easily modifiable, used in the eraser class)
let filled = false; //to make sure that no empty nodes are added to the arr[] (so that the redo works properly instead of removing empty nodes)
let type; //collected from the dropdown menu


function updatecurrent(){ // chooses the correct type of 
  if (type == 'Normal'){ //normal strokes
    
    // ignore attempts to make dynamic html
    // // let t = document.createElement('button');
    // // t.name = "HI"
    // // t.id = "randomcolour"
    // // t.onclick = "randomC()" 
    // // t.innerHTML="Random Colour">
    // document.getElementById('Settings').innerHTML
    // var t = document.createElement("BUTTON");
    // //t.id = "randomcolour"
    // t.onclick = UNDO
    // t.innerHTML = "CLICK ME";


    //document.getElementById('Settings').appendChild(t);
    
    
    current = new freehand();
  }
  else if (type == 'rainbow'){
    current = new rainbow(); //rainbow colour
  }
  else if (type == 'Eraser'){
    current = new freehand(true); //eraser (used this way because the only difference it has with normal strokes is the colour)
  }
  else if (type = 'highlighter'){
    current = new highlighter(); //highlighter
  }
  
}

class rainbow{
  constructor(){ //collects all the parameters to be stored -> always remain the same and stored even if the global variable changed
    //super();
    this.actions = []; //the positions of all the points (also found in "freehand")
    this.colours = []; //colours of each point
    this.thick=strokew;
    this.opacity=alpha;
    colorMode(HSB); //sets the colourmode to HSB temporarily -> much easier to change the colour only
    this.value = int(random(255)); //chooses the starting colour, a random hue
    colorMode(RGB);
    this.set = random([2,-2]) //randomises whether the hue increases or decrases at the start
  }

  instruct(){
    this.increase = this.set; //allows for multiple runs of instruct() -> the starting valye and starting change always remains the same
    this.colours[0] = this.value; //colour of each point is stored in an array -> this will be fixed throughout the entire thing
    for (let p=1; p<this.actions.length; p++){//for loops through the array of positions
      this.colours[p] = this.colours[p-1]+this.increase; //sets the colour of the current position -> the sum of the increase and the previous point
      if (this.colours[p] >= 255 || this.colours[p] <= 0){ //if the colour hits any edges, it reverses
        this.increase = (-1)*this.increase; //changes whether the hue increases or decreases
      }
    }
    
    colorMode(HSB); //sets to HSB temporarily to facilitate the drawing
    
    
    
    strokeWeight(this.thick);

    for (let p=1; p<this.actions.length-1; p++){
      this.colour = color(this.colours[p],100,150); //sets the colour for the current point and line
      
      stroke(this.colour) //sets the stroke colour to the assigned colour
      line(this.actions[p-1][0], this.actions[p-1][1], this.actions[p][0], this.actions[p][1]) //draws a line between the previous point and the current point
    }
    
    colorMode(RGB); //sets it back to RGB in case it disrupts any other colour functions
  }

  detect(){ //individual code here
    if (mouseIsPressed == true && mouseX >= -20){ //if the mouse is in the "working" area, add the position to the array actions
      filled = true;
      this.actions.push([mouseX, mouseY]);
    }

    else if (mouseY >= 0 && filled){ //otherwise, if the mouse is let go, the current class is pushed to the global array, and a new one is created.
      filled = false; //ensures that empty "current" classes are not pushed to the actions array (allows the undo function to work properly)
      arr.push(current);
      updatecurrent();
      redo = []; //since a change is made, the redo array is cleared
    }

    for (let i=0; i<arr.length; i++){
      arr[i].instruct(); //draw everything in the actions array by iterating through them
    }
    this.instruct(); //draw the actions in the current (allows lines and things to show up even if the mouse is not released
  }

  present(){ //work in progress (sample thing)
    this.sample = createGraphics(width/20, height/20);
    this.sample.point(this.sample.width/2, this.sample.height/2);

    image(this.sample, 0,0);
  }
}


class clear { //clear class which basically sets the background colour to default
  constructor(){

  }

  instruct(){
    background(backgroundcolour);
  }
}

class highlighter { //highliter/side pen thing
  /* concept:
  Draw slanted rectangles that goes at the same angle
  this means that moving in some directions will cause thinner lines, while other directions might cause significantly thicker lines
  */
  
  constructor(){ //standard constructor
    this.actions = [];
    this.colour = mainc;
    this.thick = strokew;
    this.change = createVector(-(this.thick*tan(60  )), -(this.thick))
  }

  instruct(){
    noStroke(); //this only uses the fill rectangle, and having a stroke will made it not nice...
    //stroke(this.colour);
    fill(this.colour);
    

    for (let p=1; p<this.actions.length-1; p++){
      beginShape(); //main rectangle
      vertex(this.actions[p].x+this.change.x, this.actions[p].y + this.change.y);
      vertex(this.actions[p].x, this.actions[p].y);
      vertex(this.actions[p+1].x, this.actions[p+1].y);
      vertex(this.actions[p+1].x+this.change.x, this.actions[p+1].y+this.change.y);
      endShape(CLOSE);

      beginShape(); //tiny rectangle, because 
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
    this.sample.ellipse(0,0,this.sample.width, this.sample.height);
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


  //pg = createGraphics(width/20, height/20);



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
  updatecurrent();

}

function saveCall(){
  saveCanvas(cnv, 'img','jpg');
}

function updateColour(){
  mainc=color(document.getElementById("colourpicka").value);
  updatecurrent();
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

  //pg.background(0);
  //image(pg,width/2,height/2);
  
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
