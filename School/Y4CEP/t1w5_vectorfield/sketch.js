let vectors = [];
let noiseScale = 0.01;
let time = 0;


function setup() {
    createCanvas(400, 400);
    for (let x=0; x<width; x+=20){
        for (let y=0; y<height; y+=20){
            let angle = noise(x*noiseScale, y*noiseScale, time)*TWO_PI;
            let v = p5.Vector.fromAngle(angle);
            vectors.push(v);
        }
    }
}

function draw() {
    background(220);
    time += 0.01;

    for (let i=0; i<vectors.length; i++){
        
    }
}