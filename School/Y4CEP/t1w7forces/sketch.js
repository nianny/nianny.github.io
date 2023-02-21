class Mover {
    constructor(x,y,m){
        this.mass = m;
        this.radius = m*8;
        this.position = createVector(x,y);
        this.velocity = createVector(0,0);
    }

    
}

function setup() {
    createCanvas(400, 400);
}

function draw() {
    background(220);
}