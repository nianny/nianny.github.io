function setup() {
    createCanvas(windowWidth, windowHeight);
    angleMode(DEGREES);
}

function draw() {
    background(0);
    // circle(100,100,50)

    beginShape();
    for (let i=0; i<=360; i++){
        let noise_x = sin(i)+100;
        let noise_y = cos(i);

        let length = map(noise(noise_x, noise_y, frameCount*0.01), 0, 1, 70, 100);

        let x = width/2 + length*sin(i);
        let y = height/2 + length*cos(i);

        vertex(x,y);
    }

    endShape(CLOSE);
}