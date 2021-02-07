let buttons = [], lights = [];
let win = false;
let alpha = 255;
let lightnum = 7;
let buttonnum = 5;


function createarrays() {
  for (let i = 0; i< buttonnum; i++){
    buttons.push(false);
  }

  for (let i = 0; i< lightnum; i++){
    buttons.push(false);
  }
}


function setup() {
  createCanvas(650, 400);
  createarrays();
}

function clickdetect() {
  if (mouseButton === LEFT){

  }
  else if (mouseButton === RIGHT){

  }
}

function drawmap () {
  background(200);

  fill(255, alpha);
  stroke(0,0,0);
  beginShape();
  vertex(10,10); //top left
  vertex(70,10); //top right of top left room
  vertex(70, 50);
  vertex(120, 50);
  vertex(120, 30);
  vertex(200, 30);
  vertex(200, 70);
  vertex(310, 70);
  vertex(310, 110);
  vertex(380, 110);
  vertex(380, 330);
  //vertex()

  vertex(200, 330);
  vertex(200, 250);
  vertex(125, 250);
  vertex(125, 270);
  vertex(150, 270);
  vertex(150, 310);
  vertex(80, 310);
  vertex(80, 270);
  vertex(105, 270);
  vertex(105, 250);
  vertex(50, 250);
  vertex(50, 140);


  vertex(25, 140)
  vertex(25, 100);
  vertex(10, 100);
  vertex(10,10);

  endShape();


  fill(0, 60);
  beginShape();
  
  vertex(70,70);
  vertex(120, 70);
  vertex(120, 90);
  vertex(290, 90);
  vertex(290,110);
  vertex(200, 110);
  vertex(200, 220);
  vertex(70, 220);
  vertex(70, 200);
  vertex(150,200);
  vertex(150, 150);
  vertex(70, 150);
  vertex(70, 180);

  vertex(70, 120);
  vertex(45,120);
  vertex(45, 100);
  vertex(70, 100);

  vertex(70,70);
  endShape();
  
  fill(255, alpha);
  noStroke();
  
  // rect(145, 170, 60, 20);
  // stroke(0,alpha);
  // line(150, 170, 200, 170);
  // line(150, 190, 200, 190);

  //noFill();
  fill(0);
  textAlign(CENTER);
  textFont('Potta One');
  textSize(20);
  textStyle(ITALIC)
  text("The Mysterious House", 200, 360);
 }

function drawbutton (){
  fill(0);
  textAlign(LEFT);
  text("Controls:", 400, 50);
}




function button (status, x, y){
  rect(x,y, 20, 40);
  if (status) {
    rect(x+5, y+14, 10, 20)
    beginShape();
    vertex(x+5, y+14);
    vertex(x+3, y+5);
    vertex(x+17, y+5);
    vertex(x+15, y+14);
    endShape()
    line(x+3, y+5, x+5, y+34);
    line(x+17, y+5, x+15, y+34);
  }
    


  //console.log(booleeen);
}

function wingame() {
  for (let i=0; i<2; i++){
    alpha = 50;
    drawmap();
    //textColor('green');
    fill(0,150,0, 255);
    textSize(25);
    textFont('Potta One');
    textAlign(LEFT);
    text("Yay you win :)", width/20*11.9, height/20*2);
    textFont('Consolas')
    textSize(15)
    text("Thank you for playing this game", width/20*11.9, height/20*3.2)
    displayanswer();
    textSize(12);
    
    text("The answers can be seen on the screen now!", width/20*11.9, height/20*4);
    fill(255,alpha);

    noLoop();
    
  }
}

function checkwin () {
  let check = true;
  for (let i=0; i<buttonnum; i++){
    //console.log(buttons[i])
    if (!buttons[i]){
      check = false;
    }
  }

  if (check){
    win = true;
  }
}

function displayanswer() {

}





function draw() {
  background(220);
  
  stroke(0, alpha);
  checkwin();




  
  //button(true, width/20*2, height/20 * 15);
  drawmap();
  drawbutton();
  if (mouseIsPressed){
    clickdetected();
  }
  

  if (win == true){
    wingame();
  }
}