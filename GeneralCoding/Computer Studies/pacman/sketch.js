
let rad = 20;
let directionx=5;
//let directiony =5;
let arr = [];
let ang = 30;
let open = true;

function setup() {
  createCanvas(400, 400);
  // while(!mouseIsPressed){
  //   //pass
  // }
  x=width/2;
  y=height/2;
  angleMode(DEGREES);
  
}

function draw() {
  background(0);
  if (open){
    ang = 30;
  }
  else{
    ang = 10;
  }
  
  if (mouseIsPressed && mouseX <= width-rad && mouseX >= 0+rad && mouseY >= 0+ rad && mouseY <= height-rad){
    x=mouseX;
    y=mouseY;
    directionx = 4;
    //directiony = 5;
  }
  fill(255)
  if (directionx >= 0){
    arc(x,y,rad*2, rad*2, ang,360-ang,PIE);
  }
  else{
    arc(x,y,rad*2, rad*2, 180+ang, 180-ang, PIE);
  }
  if (x%50 == 0){
      open = !open;
  }
  x+=directionx;
  //y+=directiony;
  stroke(0);
  //line(x,y,x-directionx,y-directiony);
  
  if ((x >= width-rad)  ||  x <= (0+rad)){
    directionx = -directionx;
    
    //directiony = -directiony;
  }
  // if ((y>= height-rad || y<=0+rad)){
  //   directiony = -directiony;
  // }
}