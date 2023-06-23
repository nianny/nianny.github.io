let speed = 0.1;

class Mass{
    constructor(x,y){
        this.position = createVector(x,y);
        this.dist = 0;
        this.init_energy();
        this.started = false; //whether the stuff are getting reset
        this.simulate = false; //whether the simulation is running
        this.toggle = false; //whether the object is moving from start to end (false), or end to start (true); important since we can only get magnitude but not direction of velocity

        this.show_velocity = true;

        this.velocity = createVector(0,0);
        this.prev_velocity = createVector(0,0);
    }

    draw(){
        if (!this.started){ //reset to first point
            this.position = distances[0];
            this.init_energy();
            this.dist = 0;
            this.toggle = false;
            this.simulate = false;
            this.velocity = createVector(0,0);
            this.prev_velocity = createVector(0,0);
        }
        else {
            if (this.show_velocity){ //shows velocity vector
                this.velocity_vector();
            }
           

            if (this.simulate){ //moves the object continuously
                this.started = true;
                this.update();
            }
        }
        push();
        noStroke();
        fill(255, 127, 17, 200);
        circle(this.position.x, this.position.y, 10);
        pop(); 
    }

    init_energy(){
        this.energy = 10*(-this.position.y);
    }

    get_v(){ //current speed (by conservation of energy)
        let current = 2*(this.energy-10*(-this.position.y));
        if (current >= 0){
            return 0.1*Math.sqrt(current);
        }
        else{
            return -0.01*Math.sqrt(-current);
        }
    }
    
    update(){ //runs every frame -> gets velocity -> add v to distance -> find position
        let prev_dist = this.dist;
        this.prev_velocity = this.velocity;

        let v = this.get_v();
        if (this.toggle){
            v = -v;
        }

        this.dist += v;
        let result = getPointByDistance(this.dist);
        
        if (result.dist == prev_dist){ //edge case handling (if it gets stuck)
            if (this.toggle && distances[max(0, result.index-1)].y > result.y){
                result = distances[max(0, result.index-1)];
            }
            else if (!this.toggle && distances[min(distances.length-1, result.index+1)].y > result.y){
                result = distances[min(distances.length-1, result.index+1)];
            }
            else{
                this.toggle = !this.toggle;
            }
        }
        this.position = result;
        this.dist = result.dist;  
        this.velocity = createVector(this.get_v()*Math.cos(result.angle), this.get_v()*Math.sin(result.angle));
        if (this.toggle){
            this.velocity.mult(-1); //flip it
        }
    }

    velocity_vector(){ //draws velocity vector
        if (this.show_velocity){
            push();
            translate(this.position.x, this.position.y);
            rotate(this.position.angle);
            fill("#42658A")

            noStroke();
            if (this.toggle){
                text("v", -(this.get_v()*10), 15);
            }
            else{
                text("v", this.get_v()*10, 15);
            }

            stroke("#42658A");
            strokeWeight(3);
            strokeJoin(ROUND);
        
            if (this.toggle){
                rotate(PI);
            }

            //arrows
            line(0,0, this.get_v()*10, 0);
            line(this.get_v()*10, 0, this.get_v()*10-3, -3);
            line(this.get_v()*10, 0, this.get_v()*10-3, 3);
            pop();
        }
    }


    //doesn't work very well
    acceleration_vector(){
        // console.log(this.velocity);

        // let acceleration = this.velocity;
        // acceleration.sub(this.prev_velocity);
        let acceleration = p5.Vector.sub(this.velocity, this.prev_velocity);

        // this.draw_vector(acceleration, 500, 500, 1000);
        // this.draw_vector(this.velocity, 500, 500, 100);
        // this.draw_vector(this.prev_velocity, 500, 500, 100);
        acceleration.mult(100);
        acceleration.sub(0,10);
        console.log(acceleration)

        push();
        stroke("#42658A");
        strokeWeight(10);
        translate(this.position.x, this.position.y);
        rotate(acceleration.heading());
        line(0,0, acceleration.mag()*10, 0);
        pop();
    }
    
    //test function for drawing vectors
    draw_vector(v, x, y, scale){
        push();
        stroke("#42658A");
        strokeWeight(1);
        translate(x, y);
        rotate(v.heading());
        line(0,0, v.mag()*scale, 0);
        pop();
    }
}