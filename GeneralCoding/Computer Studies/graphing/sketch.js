function setup() {
  createCanvas(windowWidth, windowHeight);
  size = min(width, height);
  sel = createSelect();
  sel.position(10,10);
  sel.option('Mandelbrot Set')
  sel.option('Lorenz Attractor')
  sel.changed(changeChoice)
  sel.selected('Mandelbrot Set')
  drawEverything();
  drawMandelbrot();
}

function createMandelbrot(){
  mande = createGraphics(width,height);
  mande.pixelDensity(1);
  mande.loadPixels();
  let it = 100;
  for (let x=0; x<mande.width; x++){
    for (let y=0; y<mande.height; y++){

      //mapping
      let a = map(x,0,mande.width, -1.25*width/height,0.75*width/height); 
      let b = map(y,0,mande.height,-1,1)

      let ka = a;
      let kb = b;

      let n = 0;

      for (let i=0; i<it; i++){
        let aa = a*a - b*b;
        let bb = 2*a*b;

        a = aa + ka;
        b = bb + kb;

        if (a+b > 16){
          break;
        }

        n++;
      }

      // let brightness = 0;
      // if (n == 100){
      //   brightness = 255;
      // }

      let brightness = map(n,0,100,0,255);
      if (n == it){
        brightness = 0;
      }


      //update individual pixels
      let pix = (y*mande.width + x)*4 ; // + mande.width/10*1
      mande.pixels[pix] = brightness;
      mande.pixels[pix+1] = brightness;
      mande.pixels[pix+2] = brightness;
      mande.pixels[pix+3] = 255;
    }
  }
  mande.updatePixels();
  //mande.background(0);
}


function windowResized() {
  resizeCanvas(windowWidth, windowHeight)
  size = min(width, height);
  drawEverything();
  
  changeChoice();
}
  
function draw() {
  background(0);
  image(mande, width-mande.width, height-mande.height)
}

function changeChoice(){
  if (sel.value() == 'Mandelbrot Set'){
    console.log('yay')
    drawMandelbrot();
  }
  else if (sel.value() == 'Lorenz Attractor'){

  }
}

function drawMandelbrot(){
  image(mande, 0, height-min(width, height))

}


function drawEverything(){
  createMandelbrot();
}