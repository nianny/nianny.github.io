//let a = [];
let arr = [];
let free = true;
let mainc;
let strokew;
class freehand {
  constructor(color, ){
    this.actions = [];
    this.colour=mainc;
    this.thick=strokew;
  }

  instruct(){
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
  mainc= document.getElementById("colourpicka").value;
  strokew = document.getElementById("strokewidth").value;
  cnv=createCanvas(400, 400);
  noFill();
  if (free){
    current = new freehand();
  }
  
  //current.colour = mainc;
}


function saveCall(){
  save(cnv, 'img.jpg');
}

function updateColour(){
  mainc=document.getElementById("colourpicka").value;
}

function updateStrokeWidth(){
  strokew = document.getElementById("strokewidth").value;
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