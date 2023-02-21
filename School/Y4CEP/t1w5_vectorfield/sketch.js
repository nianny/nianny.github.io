let noiseScale = 0.005;
let dotnum = 500;
let resolution = 40;
let colourScale = 0.005;

let size;
let framePassed = 0;
let vectors = [];
let colours = [];
let points = [];
function setup() {
    createCanvas(windowWidth, windowHeight);
    size = width/resolution;

    for (let i=0; i<dotnum; i++){
        let point = new Dot();
        points.push(point);
    }
    vectors = [];
    colours = [];
    for (let x=0; x<width; x+=size){
        for (let y=0; y<height; y+=size){
            let angle = noise(x*noiseScale, y*noiseScale, framePassed)*TWO_PI;
            let v = p5.Vector.fromAngle(angle);
            vectors.push(v);
            
            // push();
            // colorMode(HSB);
            let col = color(noise(x*colourScale, y*colourScale, 1)*255, noise(x*colourScale, y*colourScale, 500)*255, noise(x*colourScale, y*colourScale, 1000)*255);
            // pop();

            // col = color(noise(framePassed)*255);
            colours.push(col);
        }
    }
}

function draw() {
    background(0,0,0, 20);
    if (frameCount % 10 == 0){
        vectors = [];
        colours = [];
        for (let x=0; x<width; x+=size){
            for (let y=0; y<height; y+=size){
                let angle = noise(x*noiseScale, y*noiseScale, framePassed)*TWO_PI;
                let v = p5.Vector.fromAngle(angle);
                vectors.push(v);
                
                let col = color(noise(x*colourScale, y*colourScale, 1)*255, noise(x*colourScale, y*colourScale, 500)*255, noise(x*colourScale, y*colourScale, 1000)*255);

                // col = color(noise(framePassed)*255);
                colours.push(col);
            }
        }
        console.log(framePassed);
    }

    
    let showvec = false;
    for (let i=0; i<dotnum; i++){
        points[i].run();
    }
    if (showvec){
        for (let i=0; i<vectors.length; i++){
            let v = vectors[i];
            let x = (i%resolution)*size;
            let y = floor(i/resolution)*size;

            drawVector(v,x,y, size);
        }
    }
    framePassed += 0.005;
}

function drawVector(v, x, y, scaling){
    push();
    translate(x,y);
    stroke(255);
    rotate(v.heading());
    line(0,0,v.mag()*scaling,0);
    pop();
}

class Dot{
    constructor(){
        this.position = createVector(random(1, width-1), random(1, height-1));
        this.velocity = createVector(0,0);
        this.acceleration = createVector(0,0);
        this.mult;
        this.determineMulti();

        this.prev_pos = this.position;
    }

    applyForce(acceleration){
        this.acceleration.add(acceleration);
    }

    update(){
        this.checkEdges();
        this.velocity.add(this.acceleration);

        this.prev_pos = this.position;
        if (this.mult == 1){
            this.position.add(this.velocity);
        }
        else{
            this.position.sub(this.velocity);
        }
        this.acceleration.mult(0);
        
    }

    display(colour){
        push();
        strokeWeight(2);
        // colorMode(HSB);
        stroke(colour);
        line(this.prev_pos.x, this.prev_pos.y, this.position.x, this.position.y);
        pop();
        
    }

    checkEdges(){
        if (this.position.x >= width || this.position.x <= 0 || this.position.y >= height || this.position.y <= 0) {
            this.position = createVector(random(1, width-1), random(1, height-1));
            // this.position = createVector(width/2, height/2);
            // this.prev_position = this.position;
            this.update();
            this.determineMulti();
        }
    }

    determineMulti(){
        if (random(-1, 1) <= 0){
            this.mult = -1;
        }
        else{
            this.mult = 1;
        }
    }

    run(){
        this.checkEdges();
        let idx = floor(this.position.x / size) + floor(this.position.y/size)*resolution;
        // console.log(idx);
        let dV = vectors[idx];
        // dV.mult(this.mult);
        // console.log(this.position.x, this.position.y, idx, dV, this.mult);
        this.velocity = dV;
        this.update();
        this.display(colours[idx]);
    }
}