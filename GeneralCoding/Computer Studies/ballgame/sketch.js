let x1,x2,y1,y2,x,y;
let br = 30;
let sr = 30;
let score = 0;
let d1,d2,d;
let ballvisi = false;
let bspeed = 5;
let sc = false;

function setup() {
  createCanvas(400, 400);
  y1 = y2 = y = height/2;
  x = width/2;
  x1 = br+10;
  x2 = width - br-10;
  d1 = bspeed;
  d2 = -bspeed;
  d = bspeed/2;
  
}

function draw() {
  background(220);
  line(width/2, 0, width/2, height);
  ellipse(x1,y1,br*2);
  ellipse(x2,y2,br*2);

  y1+=d1;
  y2+=d2;

  if (y1 <= 0+br || y1 >= height-br){
    d1 = -d1;
    d2 = -d2;
  }

  if (x <= -sr || x >= width+sr){
    ballvisi = false;
  }
  console.log(x);
  console.log(d);
  
  if(mouseIsPressed && ballvisi == false){
    ballvisi = true;
    
    if(mouseButton === LEFT){
      x = width/2;
      d = -abs(d);
      y = mouseY;
    }
    else{
      x = width/2;
      d = abs(d);
      y = mouseY;
      
    }
  }
  console.log(sc);
  if ((ballvisi && dist(x,y,x1,y1) <= (br+sr)/2 || dist(x,y,x2,y2) <= (br+sr)/2) && !sc){
    score+=1;
    sc = true;
  }
  if (ballvisi){
    ellipse(x, y, sr);
    x += d;
  }
  if (!ballvisi){
    sc = false;
  }
  
  

  textAlign(CENTER);
  textSize(30);
  textFont('Potta One');
  rectMode(CENTER);
  fill(220);
  noStroke();
  rect(width/2, 40, 100, 30);

  fill(0);
  stroke(0);
  text("Score: " + str(score), width/2, 50);
  fill(255);
  
  
}