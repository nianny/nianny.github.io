let lorenza;
function setup() {
  createCanvas(windowWidth, windowHeight);
  lorenza = new lorenzClass(0, 0, 0, 10, 28, 8/3)
  size = min(width, height);
  sel = createSelect();
  sel.position(10,10);
  sel.option('Mandelbrot Set')
  sel.option('Lorenz Attractor')
  sel.changed(changeChoice)
  sel.selected('Mandelbrot Set')
  changeChoice()
  setUp();

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
    // this.lorenz = createGraphics(width, height);
    // this.lorenz.background(0);
    this.x = 0.01;
    this.y = 0.0;
    this.z = 0.0;
  
    this.arr = [];
    this.lorenz.colorMode(HSB);

    this.dx = 0
    this.dy = 0
    this.dz = 0
  }


  drawLorenz(){
    // lorenz.background(0);
    this.dt = 0.01;
    // console.log(this.x)
    // console.log(this.y)
    // console.log(this.z)
    this.dx = this.dt*(this.a*(this.y-this.x));
    this.dy = this.dt*(this.x*(this.b-this.z)-this.y);
    this.dz = this.dt*(this.x*this.y - this.c*this.z);

    this.x += this.dx;
    this.y += this.dy;
    this.z += this.dz;

    this.arr.push(createVector(this.x,this.y,this.z))
    this.lorenz.noFill();
    this.lorenz.stroke(this.hue,150,150, 100);
    // this.lorenz.translate(200,200) 
    //somehow translate doesnt work

    this.lorenz.beginShape();
    for (let i = 0; i<this.arr.length; i++){
      this.lorenz.vertex(this.arr[i].x*5 + 200, this.arr[i].y*5 + 200);
    }
    this.lorenz.endShape();
    // this.lorenz.point(this.x*5 + 200, this.y*5 + 200)
    image(this.lorenz, 0,0);
  }
}


function draw() {
  //background(0);
  drawImages()
  
}

function drawImages(){
  if (sel.value() == 'Mandelbrot Set'){
    drawMandelbrot();
    button.show();
    
  }
  else if (sel.value() == 'Lorenz Attractor'){
    //drawLorenz()button.show()
    button.hide();
    lorenza.drawLorenz();
  }
  
}

function changeChoice(){
  if (sel.value() == 'Mandelbrot Set'){
    console.log('yay')
    createMandelbrot();
  }
  else if (sel.value() == 'Lorenz Attractor'){
    background(0)
    lorenza = new lorenzClass(0, 0, 0, 10, 28, 8/3)
    lorenza.createLorenz()

    //createLorenz();
    
  }
}




function setUp(){
  button = createButton('More information');
  button.position(width/100, height/10*3);
  button.mousePressed(moreInfo);
  button.hide()
  button.class('darkButton')
  background(0)
  createMandelbrot();
  lorenza.createLorenz();
}