class Block{
    constructor(x, y){
        this.position = createVector(x,y);
    }

    draw(){
        rect(this.position.x, this.position.y, 100, 20);
    }
}