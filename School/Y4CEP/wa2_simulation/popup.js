class PopUp{
    constructor(msg, duration){
        this.msg = msg;
        this.duration = duration; //time in miliseconds
        this.start = millis();
        console.log(this.start);
    }

    show(x, y){
        push();
        noStroke();
        fill(234, 197, 216, 80);
        rect(x,y, 250, 50, 10);
        textAlign(CENTER, CENTER);
        textFont(font, 15);
        fill(0);
        text(this.msg, x+125, y+25);
        pop();
    }

    check(){
        return (millis() - this.start) > this.duration; //if duration to display alert is over
    }
}