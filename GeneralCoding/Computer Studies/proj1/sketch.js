//this is best suited if the width/height is the same (it wont distort the image)


let alpha = 180;
let backgroundocolour = 220;


function setup() {
  createCanvas(400, 400);
}

function drawBackground() {
  for (let i=0; i<1000; i++){
    fill(100,100,100,alpha);
    ellipse(floor(random(0,width)), floor(random(0,height)), ((width+height)/2)/400, ((width+height)/2)/400);
  }
}

function drawmountains() {
  stroke(0,0,0);
  //fill(100,100,100, alpha);
  beginShape();
  vertex(0, height);
  vertex(width, height);
  vertex(width, height/1.15)
  vertex(width*0.8, height/1.5)

  vertex(width/1.5, height/2);
  vertex(width/2, height/1.7)
  vertex(width/4, height/1.35)
  vertex(width/4.5, height/1.38);
  endShape(CLOSE);
}



function writeWords(){
  fill(0,0,0,alpha);
  //textAlign (CENTER);
  textFont('Potta One');
  textSize(((width+height)/2)/10);
  text("Horizon", width/30,height/8);
  fill(0,150,0,alpha);
  textSize(((width+height)/2)/16);
  text("2025", width/30, height/5);

  stroke(0,0,0,alpha);
  strokeWeight(((width+height)/2)/80);
  line(width/30, height/4.5, width/2, height/4.5);
}


  
function draw() {
  background(backgroundocolour);
  drawBackground();

  fill(backgroundocolour);
  drawmountains();
  fill(50,50,50,alpha);
  drawmountains();

  writeWords();
  noLoop();
}