//let a = [];
let arr = [];
let free = true;
let mainc;
let strokew;
let alpha;
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
  }
}

function setup() {
  document.querySelector("#setalpha").innerText="newValue";

  strokeJoin(ROUND);
  mainc= color(document.getElementById("colourpicka").value);
  strokew = document.getElementById("strokewidth").value;
  alpha = map(document.getElementById("setalpha").value,0,100,0,255);
  //mainc.setAlpha(alpha);
  console.log(mainc);
  cnv=createCanvas(400, 400);
  noFill();
  if (free){
    current = new freehand();
  }
  
  //current.colour = mainc;
}

function randomC(){
  mainc = color(floor(random(0,255)),floor(random(0,255)),floor(random(0,255)))
}

function saveCall(){
  save(cnv, 'img.jpg');
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

function eraser(){
  mainc = color(255)
}

function CLEARSCREEN(){
  arr = [];
  current = new freehand();
}


function draw() {
  
  background(250);
  if (free){
    if (mouseIsPressed == true){
      current.actions.push([mouseX, mouseY]);
    }

    else{
      arr.push(current);
      current = new freehand();
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

function keyPressed(){
  //if (keyIsDown(ControlLeft)){
    if(keyIsDown(KeyH)){
      textAlign(CENTER);
      text("HALLO",width/2, height/2);
    }
  //}
}
