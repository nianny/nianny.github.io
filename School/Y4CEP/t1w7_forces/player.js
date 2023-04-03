class Player{
    constructor(x, y){
        this.position = createVector(x,y);
        this.velocity = createVector(0,-10);
        this.acceleration = createVector(0, 0.2);
        this.radius = 50;
    }


    update(){
        this.velocity.add(this.acceleration);
        this.position.add(this.velocity);

        if (this.position.x < 0){
            this.position.x = width;
        }
        if (this.position.x > width){
            this.position.x = 0;
        }
    }

    draw(){
        circle(this.position.x, this.position.y, this.radius);
    }

    checkCollision(blocks){
        for (let i=blocks.length-1; i>=0; i--){
            let block = blocks[i];

            if (abs(this.position.x - block.position.x) <= (this.radius/2 + 50) && block.position.y - this.position.y >= 0 && block.position.y - this.position.y <= (this.radius/2+10)&&this.velocity.y > 0){
                console.log(block);
                this.velocity = createVector(0, -10);
                return block.position.y;
            }
        }
    }

    get_y(){
        return this.position.y;
    }

    moveHorizontal(dist){
        this.position.x += dist;
    }
}