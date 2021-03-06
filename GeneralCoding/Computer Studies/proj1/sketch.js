//this is best suited if the width/height is the same (it wont distort the image)

//if necessary, please remember to reload so as to allow the fonts to laod in


let alpha = 180;
let backgroundocolour = 220;


function setup() {
  createCanvas(400, 400);
}

function drawBackground() {
  for (let i=0; i<100; i++){
    fill(100,100,100,alpha);
    ellipse(floor(random(0,width)), floor(random(0,height)), ((width+height)/2)/400, ((width+height)/2)/400);
  }
}

function drawSun(){
  strokeWeight(3);
  fill(200,200,100);
  ellipse(width/2, height/2, width/400*100);
  fill(80);
  strokeWeight(1);
}

function drawmountains() {
  stroke(0,0,0);
  //fill(100,100,100, alpha);

  beginShape();
  vertex(width/7, height);
  vertex(width/3*1, height/2*1.2); 
  vertex(width/3*2.5, height);
  endShape(CLOSE);

  beginShape();
  vertex(width/20*12, height);

  vertex(width/20*18, height/20*12);
  vertex(width*1.4, height);
  endShape(CLOSE);
















  beginShape();
  vertex(0, height);
  vertex(width, height);
  vertex(width, height/1.15)
  vertex(width*0.8, height/1.6)

  vertex(width/1.5, height/2);
  vertex(width/2, height/1.7)
  vertex(width/3.2, height/1.3)
  vertex(width/4.4, height/1.38);
  endShape(CLOSE);

  

  line(width/3.2, height/1.3, width/10*0.3, height);

  noStroke();
  fill(130,alpha);
  triangle(width/20*0.7, height/20*19.7, width/20*4.5, height/20*15, width/20*4.5, height/20*16.3);

  triangle(width/20*6.6, height/10*6.3, width/20*5.7, height/10*7.4, width/20*6.3, height/10*7.55);

  beginShape();
  vertex(width/20*18.1, height/20*12.55);
  vertex(width/20*18.1, height/20*14.7);
  vertex(width/20*20, height/20*17);
  vertex(width, height/20*14.1);
  endShape(CLOSE);



  fill(255,alpha);
  triangle(width/20*4.7, height/20*15, width/20*4.75, height/20*16.25, width/20*5.75, height/20*15.5);

  triangle(width/20*6.8, height/20*12.6, width/20*6.55, height/20*14.8, width/20*7.9, height/20*13.5);

  triangle(width/20*17.9, height/20*12.55, width/20*17.2, height/20*13.5, width/20*17.9, height/20*14.5)

  



  
  
  stroke(0);
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
  fill(80);
  drawSun();
  drawmountains();

  

  writeWords();
  noLoop();
}