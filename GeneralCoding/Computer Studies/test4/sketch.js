function setup() {
    createCanvas(500, 200);
}
  
function draw() {
  background(220);
  rect(width/5,0,width/5*3,height); //draw rectangle
  triangle(width/2, 0, width/5, height/2, width/5*4, height/2); //draw triangle

  //draw circles
  ellipse(0, height/2, height);
  ellipse(width, height/2, height);
}