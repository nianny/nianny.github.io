//let a = [];
let b = [];
// class freehand {
//   constructor()
// }

function setup() {
  createCanvas(400, 400);
  noFill();
  b.push([]);
}
        

function draw() {
  background(250);
  //let a = [];
  if (mouseIsPressed == true){
    b[b.length-1].push([mouseX, mouseY]);

  }
  else {
    b.push([]);
  }
  for (let p=0; p<b.length; p++){
    beginShape();
    for (let i=0; i<b[p].length; i++){
      vertex(b[p][i][0], b[p][i][1]);
    }
    endShape();
  }
}