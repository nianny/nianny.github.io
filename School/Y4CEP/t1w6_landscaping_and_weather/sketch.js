let blobs = [];

function setup() {
    createCanvas(windowWidth, windowHeight);
    angleMode(DEGREES);
    for (let i=0; i<200; i++){
        blobs.push(new Blobby());
    }
    noStroke();
    // blob = new Blobby();
}

function draw() {
    background(0);
    // circle(100,100,50)

    for (let blob of blobs){
        blob.display();
        blob.update();
    }
}
