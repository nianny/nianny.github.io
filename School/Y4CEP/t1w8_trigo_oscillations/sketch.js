let player;

function setup() {
    createCanvas(windowWidth, windowHeight);
    player = new Player();
}

function draw() {
    background(220);


    player.update();
    player.display();
}