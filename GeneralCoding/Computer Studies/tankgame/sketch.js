let points = [];

class tank(){
  
}

function resetPoints(){
  points = [createVector(0,height), createVector(0, floor(random(height/10*8, height/10*9))), createVector(width/3, floor(random(height/10*8, height/10*9))), createVector(width/2, floor(random(height/10*8, height/10*9))), createVector(width/3*2, floor(random(height/10*8, height/10*9))), createVector(width, floor(random(height/10*8, height/10*9))), createVector(width,height)];  
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  resetPoints(); 
}

function drawLandscape(){
  beginShape()
  for (let i=0; i<points.length; i++){
    curveVertex(points[i].x, points[i].y)
  }
  endShape(CLOSE);
}

function draw() {
  background(150);
  //drawLandscape();

  rect(0, height/10*9, width, height/10);



}