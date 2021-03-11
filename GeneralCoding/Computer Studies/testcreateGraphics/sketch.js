function setup() {
    createCanvas(400, 400);
    pg = createGraphics(50,50);
}
  
function draw() {
  pg.background(0);
  background(220);
  image(pg, 0,0)
}