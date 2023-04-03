let player;
let blocks;
let lines;

let game_height;
let lowest = 50;

let offset = 0;
let remaining_offset = 0;

let next_block;
let next_line;
let blocks_since_blocks = 0;
function setup() {
    createCanvas(500, windowHeight);
    rectMode(CENTER);
    textAlign(CENTER, CENTER);
    fill(20);

    next_block = height - lowest;
    next_line = height-lowest+10;
    game_height = Math.floor((height-100)/40)*40;
    offset = 0;
    lowest = 50;
    remaining_offset = 0;
    blocks_since_blocks = 0;

    console.log(game_height);


    player = new Player(width/2, height);
    blocks = [];
    lines = [];

    blocks.push(new Block(width/2, next_block));
    next_block -=40;
    for (let i=0; i<game_height; i+=40){
        if (blocks_since_blocks > 5){
            blocks.push(new Block(random(60, width-60), next_block));
            blocks_since_blocks = 0;
        }
        else{
            if (generateblockprob()){
                blocks.push(new Block(random(60, width-60), next_block));
                blocks_since_blocks = 0;
            }
        }
        blocks_since_blocks++;
        next_block -= 40;
    }

    for (let i=0; i<=game_height+20; i+=20){
        lines.push(next_line);
        next_line -= 20;
    }

}
//let each "block have height 40", with each piece having height 20

function draw() {
    background(220);
    textFont('Righteous');
    textSize(width/10);
    text("Score: " + offset, width/2, 30);
    
    stroke(200, 155, 155,150);
    for (let i=0; i<width; i+=20){
        line(i, height-lowest-game_height-10, i, height);
    }

    translate(0, offset);
    
    for (i of lines){
        line(0, i, width, i);
    }

    noStroke();
    if (remaining_offset > 0) {
        offset += 5;
        remaining_offset -= 5;
    }

    for (let block of blocks){
        block.draw();
    }
    player.draw();
    player.update();
    let collision = player.checkCollision(blocks);
    if (collision){
        remaining_offset = 0;
        remaining_offset = (height-50-40*2-collision)-offset;
        // console.log(offset);
    }

    checkKeys();

    for (let i = blocks.length-1; i>=0; i--){
        if (blocks[i].position.y + offset> height){
            blocks.splice(i, 1);
        }
    }

    for (let i=lines.length-1; i>=0; i--){
        if (lines[i] + offset > height){
            lines.splice(i, 1);
        }
    }

    if (next_block >= height - lowest - game_height - offset){
        if (blocks_since_blocks > 5){
            blocks.push(new Block(random(60, width-60), next_block));
            blocks_since_blocks = 0;
        }
        else{
            if (generateblockprob()){
                blocks.push(new Block(random(60, width-60), next_block));
                blocks_since_blocks = 0;
            }
        }
        blocks_since_blocks++;
        next_block -= 40;
    }
    if (next_line >= height - lowest - game_height - offset-10){
        lines.push(next_line);
        next_line -= 20;
    }
    console.log(player.get_y());
    if (player.get_y() + offset > height){
        reset();
    }
}

function checkKeys(){
    if (keyIsDown(LEFT_ARROW)){
        player.moveHorizontal(-3);
    }
    else if (keyIsDown(RIGHT_ARROW)){
        player.moveHorizontal(3);
    }
}

function generateblockprob(){
    if (offset < 1000){
        return random()<0.5;
    }
    else if (offset < 5000){
        return random()<0.3;
    }
    else if (offset < 10000){
        return random()<0.2;
    }
    else{
        return random()<0.1;
    }
    // return random() < 0.4;
}

function reset(){
    setup();

}