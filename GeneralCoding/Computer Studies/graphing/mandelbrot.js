function createMandelbrot(){
  // button.show()
  mande = createGraphics(width,height);
  mande.pixelDensity(1);
  mande.loadPixels();
  let it = 50;
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

      let brightness = map(n,0,it,0,1);
      //console.log(n)


      //colorMode(HSB)
      //update individual pixels
      let pix = (y*mande.width + x)*4 ; // + mande.width/10*1
      mande.pixels[pix] = 255*brightness;
      mande.pixels[pix+1] = 255*brightness;
      mande.pixels[pix+2] = 255*brightness;
      mande.pixels[pix+3] = 255;

      if (n == it){
        mande.pixels[pix] = 0;
        mande.pixels[pix+1] = 0;
        mande.pixels[pix+2] = 0;
      }
      //colorMode(RGB)
    }
  }
  mande.updatePixels();
  //mande.background(0);
}

function drawMandelbrot(){
  image(mande, width-mande.width, height-mande.height)
  fill(255)
  // rect(width/20, height/20, width/10, height/10)
  stroke(255);
  textFont('Potta One')
  //textAlign(CENTER);
  textSize(20);
  text("The Mandelbrot Set", width/100, height/10)
  textSize(15);
  text("The Mandelbrot Set is one of the most famous of fractals, named after Benoit Mandelbrot.", width/100, height/10*1.5);
  text("It is a set based on the equation of Zn = Z^2 + c, where c is a complex number.", width/100, height/10*1.8)
  text("The dark areas at the centre are those at which the variable Z remains stable,", width/100, height/10*2.1)
  text("with the Z starting at 0, the real part of c being the y-axis", width/100, height/10*2.4)
  text("and the imaginary part of c being the y-axis.", width/100, height/10*2.7)
  // let inp = createInput();
  // inp.position(0, 0);
  // inp.size(100);

  

}

function moreInfo(){
  window.open("mandelbrot.html")
}


  