var birdlocation = [];

function setup() {
    createCanvas(400, 400);
    // for (let i=0; i<6; i++){
    //   birdlocation.push([floor(random()), floor(random())])
    // }
}

function drawbird(a,b){
  beginShape();
  vertex(a,b);
  vertex(a+8, b-3);
  vertex(a+5, b-5);
  vertex(a-10, b-5);
  vertex(a-1, b+7);
  vertex(a+2.5, b+8);
  vertex(a,b);


  endShape();
  // console.log(a);
  // console.log(b);
}

function mountain(){
  fill(10, 100, 60);
  stroke(0);
  beginShape();
  vertex(0, height/8*5);
  vertex(width/3, height/3);
  vertex(width/2, height/2);
  vertex(width/4*3, height/4*0.5);
  vertex(width, height/8*5);

  endShape();

  fill(20, 150, 100);
  beginShape();
  vertex(width/4*1.2, height/8*5);
  vertex(width/2, height/4);
  vertex(width/4*3.5, height/8*5);
  endShape();
}
  
function draw() {
  background(100,180,200);
  

  noStroke()
  fill('yellow');
  ellipse(width/9, height/9, width/5, height/5);

  noStroke();
  fill(100,255,100);
  rect(0, height/5*4, width, height/5);
  
  translate(0, height/5*4-height/8*5);
  mountain();
  translate(0, -(height/5*4-height/8*5));

  stroke(50)
  fill(50);
  drawbird(width/2,height/2);
  drawbird(width/3*1.3, height/3*1.3);
  drawbird(width/3*2, height/3);
  drawbird(width/3*1.85, height/3*1.4);
  drawbird(width/3*1.2, height/4*1.1)

  
  line(0, height/2, width,height/2);
  line(width/2, 0, width/2,height)
  //draws the aiming thingi
}