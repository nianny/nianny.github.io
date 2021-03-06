function setup() {
  createCanvas(600, 400);
  background(200);
  fill(235)
  strokeWeight(2)
  rect (49,49,576,375)
  strokeWeight(0)
  fill(200)
  x = 5
  y = 'black'
  var colorR
  var colorG
  var colorB
  }

function draw() {

  //limitation of pen
  fill(210)
  strokeWeight(0)
  stroke(100)
  rect (0,0, width, 50)
  rect (0,0, 50, height)
  fill(215)
  strokeWeight(2)
  rect (0,320,150,80)
  fill(245)
  rect (60,330,30)
  rect (60,365,30)
  rect (25,365,30)
  rect (95,365,30)
  fill(150)
  ellipse(75,345,20)
  strokeWeight(x)
  stroke(y) //show pen color
  ellipse(27,175,5)
  
  strokeWeight(2)
  stroke(100)
  beginShape()
  vertex (65,370)
  vertex (65,390)
  vertex (85,390)
  vertex (85,370)
  vertex (65,370)
  endShape()
  strokeWeight(0)
  fill(0)
  textSize(7)
  textFont('blahblahblah') //just to reset
  text('RESET', 98,382)
  text('RESET', 28,382)
  textSize(10)
  text('Keyboard', 5,335)
  textSize(20)
  textFont('Caveat')
  fill(y) //show pen color
  text('Speed', 10,23)
  text('DRAW', 20, 38)
  
  //stroke(y)
  strokeWeight(x)
  buttonA = createButton ('Red')
  buttonA.position (85,15)
  buttonA.mousePressed(changeRD)
 
  buttonB = createButton ('Blue')
  buttonB.position (135,15)
  buttonB.mousePressed(changeBL)
  
  buttonC = createButton ('Black')
  buttonC.position (190,15)
  buttonC.mousePressed(changeBK)
  
  buttonD = createButton ('Yellow')
  buttonD.position (250,15)
  buttonD.mousePressed(changeYL)
  
  buttonE = createButton ('Green')
  buttonE.position (315,15)
  buttonE.mousePressed(changeGR)
  
  buttonF = createButton ('+')
  buttonF.position (15,100)
  buttonF.mousePressed(plus)
  
  buttonF = createButton ('--')
  buttonF.position (14.5,125)
  buttonF.mousePressed(minus)

  buttonY = createButton ('Eraser')
  buttonY.position (458,15)
  buttonY.mousePressed(eraseS)
  
  buttonX = createButton ('CLEAR')
  buttonX.position (525,15)
  buttonX.mousePressed(clearS)
  
  buttonZ = createButton ('Random')
  buttonZ.position (380,15)
  buttonZ.mousePressed(changeRandom)
  
  
  //SHAPE BUTTONS
  if (keyCode === UP_ARROW){
    if (mouseIsPressed){
      fill(y)
      strokeWeight(0)
      circle (mouseX, mouseY, x*2)
  }
  }
    
  if (keyCode === DOWN_ARROW){
    if (mouseIsPressed){
      fill(y)
      strokeWeight(0)
      rect (mouseX-(x/3 *2), mouseY-(x/3 *2), x*1.5)

    }
  }
  
  
  //RESET BUTTONS
  if (keyCode === LEFT_ARROW){
    if (mouseIsPressed){
      strokeWeight(x)

    }
  }
  
  if (keyCode === RIGHT_ARROW){
    if (mouseIsPressed){
      strokeWeight(x)}}
  
  
  //DRAW FUNCTION
  if (mouseIsPressed){
    //if (mouseX > 49 && mouseY > 50){
    //stroke(y)
    line (pmouseX, pmouseY, mouseX, mouseY)
    }

//}

}

function changeRandom(){
  //let randomColors = ['red','green','blue','orange','yellow','grey','pink','purple','white','lightgreen','lightblue','darkblue','darkgreen','brown','forestgreen','black','']
  //y = random(255)
  stroke(random(255), random(255), random(255))
  stroke(random(255), random(255), random(255));
  
  console.log("random")
  
}

function plus(){
  if (x <= 30 && x >= 1){
  x = x+2
}
}

function minus(){
  if (x <= 30 && x >= 2){
  x = x-2
}
}

function clearS(){
  strokeWeight(0)
  fill(235)
  rect (50,50,575,375)
  //clear()
  //background(235)
}
  
function eraseS(){
  y = (235)
  stroke(y)
}
 
function changeRD(){
  y = 'red'
  stroke(y)
}
 
function changeBL(){
  y = 'blue'
  stroke(y)
}
  
function changeBK(){
  y = 'black'
  stroke(y)
}

function changeYL(){
  y = 'yellow'
  stroke(y)
}
  
function changeGR(){
  y = 'green'
  stroke(y)
}
