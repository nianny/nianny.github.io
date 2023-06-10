class Player{
    constructor(){
        this.position = createVector(width/2, height/2);
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(0,0);
        this.topspeed = 4;
        // this.r = 16;
    }

    update(){
        // let mouse = createVector(mouseX, mouseY);
        // let dir = p5.Vector.sub(mouse, this.position);
        // dir.normalize();
        // dir.mult(0.5);
        // this.acceleration = dir;

        this.velocity.add(this.acceleration);

        if (keyIsDown(UP_ARROW)){
            this.velocity.add(createVector(0, -5));
        }
        if (keyIsDown(DOWN_ARROW)){
            this.velocity.add(createVector(0,5));
        }
        if (keyIsDown(LEFT_ARROW)){
            this.velocity.add(createVector(-5,0));
        }
        if (keyIsDown(RIGHT_ARROW)){
            this.velocity.add(createVector(5, 0));
        }

        this.velocity.limit(this.topspeed);
        this.position.add(this.velocity);
        this.velocity.mult(0);
        // this.acceleration.mult(0);
        

        this.checkEdges();
    }

    checkEdges(){
        if (this.position.x > width){
            this.position.x = width;
        }
        else if (this.position.x < 0){
            this.position.x = 0;
        }

        if (this.position.y > height){
            this.position.y = height;
        }
        else if (this.position.y < 0){
            this.position.y = 0;
        }
    }

    display(){
        circle(this.position.x, this.position.y, 50);
    }
}