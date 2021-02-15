//let a = [];
let arr = [];
let free = true;
class freehand {
  constructor(color, ){
    this.actions = [];
  }

  instruct(){
    beginShape();
    for (let p=0; p<this.actions.length; p++){
      vertex(this.actions[p][0], this.actions[p][1]);
    }
    endShape();
  }
}

function setup() {
  createCanvas(400, 400);
  noFill();
  if (free){
    current = new freehand();
  }
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