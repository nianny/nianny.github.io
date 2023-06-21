class PopUp{
    constructor(msg, duration){
        this.msg = msg;
        this.duration = duration;
    }

    show(x, y){
        push();
        noStroke();
        fill("#EAC5D8");
        rect(x,y, 200, 50, 10);
        textAlign(CENTER, CENTER);
        textFont("Pangolin", 15);
        stroke(0);
        text(this.msg, x+100, y+25);
        this.duration -= 1;
        pop();
    }
}