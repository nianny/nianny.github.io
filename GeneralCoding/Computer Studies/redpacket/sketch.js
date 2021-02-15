function setup() {
    createCanvas(400, 400);
    angleMode(DEGREES);
}
  

function coins(a,b) {
  fill(255,200,100);
  stroke(200,150,70);
  strokeWeight(2);
  ellipse(a,b,50);
  fill(255);
  rect(a-10, b-10, 20,20);

  stroke(0);
  strokeWeight(1);


}

function draw() {
  background(220);
  fill(200,100,100);

  
  ellipse(width/2, height/3*0.9, width/4*1.5);
  arc(width/2, height/7, width/8, width/8, 200, 340);

  rect(width/4*1.2, height/3*0.8, width/4*1.6, height/3*2.1);

  textAlign(CENTER);
  fill(255, 200, 100);
  textFont('Potta One');
  text("Happy Lunar New Year!", width/2, height/2);
  text("新年快乐", width/2, height/3*1.6)

  coins(width/2, height/2*1.3);
  coins(width/3*1.35, height/3*2.2);
  coins(width/3*1.65, height/3*2.2);
  
  
}