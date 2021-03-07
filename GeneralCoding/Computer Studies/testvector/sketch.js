function setup() {
    createCanvas(400, 400);
    arr = [[50,50], [350,50], [350,350], [50,350]]
    colorMode(HSB);
}
  
function draw() {
  background(220);
  for (let i=1; i<arr.length; i++){
    stroke(i*50, 150,200);
    line(arr[i-1][0], arr[i-1][1], arr[i][0], arr[i][1])
  }
}