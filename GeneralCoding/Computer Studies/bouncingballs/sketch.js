
let rad = 50;
let dx=40,dy=50
let directionx=dx;
let directiony =dy;

let arr = [];

function setup() {
  createCanvas(400, 400);
  // while(!mouseIsPressed){
  //   //pass
  // }
  x=width/2;
  y=height/2;
  
}

function draw() {
  background(0);
  if (mouseIsPressed && mouseX <= width-rad && mouseX >= 0+rad && mouseY >= 0+ rad && mouseY <= height-rad){
    x=mouseX;
    y=mouseY;
    directionx = dx;
    directiony = dy;
  }
  fill(255)
  ellipse(x,y,rad*2);
  x+=directionx;
  y+=directiony;
  stroke(0);
  //line(x,y,x-directionx,y-directiony);
  
  if ((x >= width-rad)  ||  x <= (0+rad)){
    directionx = -directionx;
    
    //directiony = -directiony;
  }
  if ((y>= height-rad || y<=0+rad)){
    directiony = -directiony;
  }
}