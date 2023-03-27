class Blobby{
    constructor(){
        this.reset();
        this.position = createVector(random(0, width), random(0, height));
    }

    applyForce(force){
        this.accleration.add(force);
    }

    update(){
        this.velocity.add(this.acceleration);
        this.position.add(this.velocity);
        this.acceleration.mult(0);

        this.checker();
    }

    display(){
        beginShape();
        for (let i=0; i<=360; i+=10){
            let noise_x = sin(i)+this.offset;
            let noise_y = cos(i);

            let length = map(noise(noise_x, noise_y, frameCount*0.01), 0, 1, 0.7, 1)*this.radius;

            let x = this.position.x + length*sin(i);
            let y = this.position.y + length*cos(i);

            vertex(x,y);
        }

        endShape(CLOSE);
    }

    reset(){
        this.mass = this.random_mass();
        this.radius = this.mass*8;
        this.position = createVector(random(0, width), random(-100, 0));
        this.velocity = createVector(0, this.mass);
        this.acceleration = createVector(0, 0);
        this.offset = random(100, 1000);
    }

    random_mass(){
        let a = random(0.2, 2);
        let b = random(0.2, 2);
        while(a > b){
            a = random(0.2, 2);
            b = random(0.2, 2);
        }
        return b;
    }

    checker(){
        if ((this.position.y - this.radius) > height){
            this.reset();
        }
    }
}

