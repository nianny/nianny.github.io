function setup() {
    createCanvas(400, 400);
}

function drawbird(a,b){
  console.log(a);
  console.log(b);
}
  
function draw() {
  background(220);
  line(0, height/2, width,height/2);
  line(width/2, 0, width/2,height)
  //draws the aiming thingi

  noStroke()
  fill('yellow');
  ellipse(width/9, height/9, width/5, height/5);

  stroke(0)
  drawbird(5,5);

}