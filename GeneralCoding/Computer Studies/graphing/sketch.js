let lorenza;
function setup() {
  createCanvas(windowWidth, windowHeight);
  lorenza = new lorenzClass(200, 0, 0, 10, 28, 10/3)
  size = min(width, height);
  sel = createSelect();
  sel.position(10,10);
  sel.option('Mandelbrot Set')
  sel.option('Lorenz Attractor')
  sel.changed(changeChoice)
  sel.selected('Lorenz Attractor')
  drawEverything();

  drawImages();
  //drawMandelbrot();

  
}

class lorenzClass{
  constructor(hue, posx, posy,a,b,c){
    this.hue = hue;
    this.posx = posx;
    this.posy = posy;
    this.a = a;
    this.b = b;
    this.c = c;
    this.arr = [];
    this.lorenz = createGraphics(width, height);
    this.dx;
    this.dy;
    this.dx;
    this.x;
    this.y;
    this.z;
  }

  createLorenz(){
    this.lorenz = createGraphics(width, height);
    this.lorenz.background(0);
    this.x = 0.01;
    this.y = 0.0;
    this.z = 0.0;
  
    this.arr = [];
    this.lorenz.colorMode(HSB);
  }


  drawLorenz(){
    // lorenz.background(0);
    this.dt = 0.01;

    this.dx = this.dt*(this.a*(this.y-this.x));
    this.dy = this.dt*(this.x*(this.b-this.z)-this.y);
    this.dz = this.dt*(this.x*this.y - this.c*this.z);

    this.x += this.dx;
    this.y += this.dy;
    this.z += this.dz;

    this.arr.push(createVector(this.x,this.y,this.z))
    this.lorenz.noFill();
    this.lorenz.stroke(this.hue,150,150);
  
    this.lorenz.beginShape();
    for (let i = 0; i<this.arr.length; i++){
      this.lorenz.vertex(this.arr[i].x*5, this.arr[i].y*5, this.arr[i].z*5);
    }
    this.lorenz.endShape();

    image(this.lorenz, 0,0);
  }
}


function windowResized() {
  resizeCanvas(windowWidth, windowHeight)
  size = min(width, height);
  drawEverything();
  
  changeChoice();
}
  
function draw() {
  //background(0);
  drawImages()
  
}

function drawImages(){
  if (sel.value() == 'Mandelbrot Set'){
    drawMandelbrot();
  }
  else if (sel.value() == 'Lorenz Attractor'){
    //drawLorenz();
    lorenza.drawLorenz();
  }
  
}

function changeChoice(){
  if (sel.value() == 'Mandelbrot Set'){
    console.log('yay')
    createMandelbrot();
  }
  else if (sel.value() == 'Lorenz Attractor'){
    lorenza.createLorenz();
    //createLorenz();
    
  }
}




function drawEverything(){
  createMandelbrot();
  //createLorenz();
}



function createLorenz(){
  lorenz = createGraphics(width, height, WEBGL);
  lorenz.background(0);
  x = 0.01;
  y = 0.0;
  z = 0.0;

  a = 10;
  b = 28;
  c = 10/3;

  arr = [];
  lorenz.colorMode(HSB);

  

}

function drawLorenz(){
  // lorenz.background(0);
  let dt = 0.01;

  let dx = dt*(a*(y-x));
  let dy = dt*(x*(b-z)-y);
  let dz = dt*(x*y - c*z);

  x += dx;
  y += dy;
  z += dz;

  arr.push(createVector(x,y,z))


  let hue = 0;
  //point(x,y,z);
  //print(x,y,z);
  

  lorenz.noFill();
  // lorenz.beginShape();
  // for (let i = 1; i<arr.length; i++){
  //   lorenz.stroke(hue,150,150);
  //   lorenz.line(arr[i-1].x*8, arr[i-1].y*8, arr[i].x*8, arr[i].y*8);//,   arr[i].z);
  //   hue+=0.05;

  //   if (hue > 255){
  //     hus = 0;
  //   }
  // }
  lorenz.stroke(0,150,150);

  lorenz.beginShape();
  for (let i = 0; i<arr.length; i++){
    lorenz.vertex(arr[i].x*5, arr[i].y*5, arr[i].z*5);
  }
  lorenz.endShape();
  //lorenz.scale(5);
  // lorenz.point(lorenz.width/2+x*8,lorenz.height/2+y*8, z);

  
  



  image(lorenz, 0,0);

}