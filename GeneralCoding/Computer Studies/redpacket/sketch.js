function setup() {
    createCanvas(400, 400);
    angleMode(DEGREES);
}
  
function draw() {
  background(220);
  fill(200,100,100);

  
  ellipse(width/2, height/3*0.9, width/4*1.5);
  arc(width/2, height/7, width/8, width/8, 200, 340);

  rect(width/4*1.2, height/3*0.8, width/4*1.6, height/3*2.1);

  
}