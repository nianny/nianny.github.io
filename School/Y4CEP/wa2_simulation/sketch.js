let font = "Pangolin"
let buffer_width = 100; //width of control menu
let new_point_mode = false; //used in feature where you click on "add" button, drag mouse across screen, and click again to add a point
let generated = false; //initial generation, reduce unnecessary calculations

let background_circles = []; //background
let distances = []; //precomp of points along the curve and its distance from the start (allows for search/estimation by distance)
let points = [
    [150, 50],
    [200, 100],
    [250, 50],
    [300, 100],
    [350, 50],
    [400, 100]
]

//calculation stuff
let c_matrix = [];
let inverse_of_141;
let b_matrix = [];
let beziers = [];

//dragging of points (current point being dragged)
let current_hover = null;

let obj; //object to be simulated

let alert_list = []; //custom alerts???

//buttons
let button_addpoint;
let button_removepoint;
let button_reset;
let button_start;
let button_stop;
let button_step;
let button_velocity;

//slider
let slider_step;


function preload(){
    inverse_of_141 = loadJSON('inverse.json'); //loads precomputed matrix inverse (precomputed using numpy)
    console.log(inverse_of_141);
}

function setup() {
    createCanvas(windowWidth, windowHeight);
    angleMode(RADIANS);
    generateBackground();

    textFont(font, 15);

    //init buttons
    button_addpoint = new Clickable();
    button_removepoint = new Clickable();
    button_reset = new Clickable();
    button_start = new Clickable();
    button_stop = new Clickable();
    button_step = new Clickable();
    button_velocity = new Clickable();
    init_buttons();

    //init slider
    slider_step = createSlider(5, 30, 5);
    slider_step.position(20, 330);
    slider_step.style('width', '56px');

    obj = new Mass(100, 100);
}

function draw() {
    //background
    background(220);
    drawBackground();
    noStroke();


    if (current_hover != null || !generated){ //whether to recalculate the bezier curves and distances
        calc();
    }

    //control menu
    fill("#AFBED1");
    rect(0,0, buffer_width, height);

    push();
    stroke(0);
    strokeWeight(1);
    fill(0);
    textSize(20);
    textAlign(CENTER, CENTER);
    text("Controls", 50, 40);
    textSize(15);
    text("Points", 50, 70);
    text("Simulate", 50, 215);
    text("Vectors", 50, 375);
    pop();

    //draw points
    for (let point of points){
        fill(0);
        circle(point[0], point[1], 15);
        fill(0,0,0,50);
        circle(point[0], point[1], 30);
    }

    //draw curves
    noFill();
    stroke("black");
    strokeWeight(2);
    for (let i=0; i<beziers.length; i++){
        bezier(beziers[i][0][0], beziers[i][0][1], beziers[i][1][0], beziers[i][1][1], beziers[i][2][0], beziers[i][2][1], beziers[i][3][0], beziers[i][3][1]);
    }


    if (new_point_mode && mouseX > buffer_width){//allows for the fancy ish adding point sequence
        points.push([mouseX, mouseY]);
        current_hover = points.length-1;
        new_point_mode = false;
    }

    draw_buttons();
    
    obj.draw();

    //draw alerts
    for (let i=0; i<alert_list.length; i++){
        alert_list[i].show(width-260, 10+60*i);
        if (alert_list[i].check()){
            alert_list.splice(i, 1);
        }
    }
}

function draw_buttons(){ //draws the buttons/clickables (used in control menu)
    button_step.text = "Step: " + slider_step.value();

    button_addpoint.draw();
    button_removepoint.draw();
    button_reset.draw();
    button_start.draw();
    button_stop.draw();
    button_step.draw();
    button_velocity.draw();
}

//calculate beziers and distances
function calc(){
    c_matrix = [];
    b_matrix = [];
    beziers = [];
    distances = [];
    obj.started = false;
    for (let i=1; i<=points.length-2; i++){
        if (i==1){  
            c_matrix.push([points[i][0]*6-points[i-1][0], points[i][1]*6-points[i-1][1]]);
        }
        else if (i==points.length-2){
            c_matrix.push([points[i][0]*6-points[i+1][0], points[i][1]*6-points[i+1][1]]);
        }
        else{
            c_matrix.push([6*points[i][0], 6*points[i][1]]);
        }
    }
    b_matrix.push(points[0]);
    let b_part = math.multiply(inverse_of_141[points.length-2], c_matrix)
    for (let i=0; i<b_part.length; i++){
        b_matrix.push(b_part[i]);
    }
    b_matrix.push(points[points.length-1]);


    for (let i=0; i<points.length-1; i++){
        beziers.push([points[i], [1/3*b_matrix[i+1][0]+2/3*b_matrix[i][0], 1/3*b_matrix[i+1][1]+2/3*b_matrix[i][1]], [2/3*b_matrix[i+1][0]+1/3*b_matrix[i][0], 2/3*b_matrix[i+1][1]+1/3*b_matrix[i][1]], points[i+1]]);
    }

    //distance list generation
    let total_dist=0;
    let prev_x = beziers[0][0][0];
    let prev_y = beziers[0][0][1];
    let idx = 0;
    for (let i=0; i<beziers.length; i++){
        for (let t=0; t<=1; t+=0.001){
            let x = (1-t)**3*beziers[i][0][0]+3*(1-t)**2*t*beziers[i][1][0]+3*(1-t)*t**2*beziers[i][2][0]+t**3*beziers[i][3][0]; // wow github copilot wrote this ish and i checked it and it seems legit
            let y = (1-t)**3*beziers[i][0][1]+3*(1-t)**2*t*beziers[i][1][1]+3*(1-t)*t**2*beziers[i][2][1]+t**3*beziers[i][3][1];

            total_dist += math.sqrt((x-prev_x)**2+(y-prev_y)**2);
            let angle = Math.atan2(y-prev_y, x-prev_x);
            prev_x = x;
            prev_y = y;

            distances.push({dist: total_dist, x: x, y: y, index: idx, angle:angle});
            idx++;
        }
    }
    distances[0].angle = distances[1].angle;
    generated = true;
    // console.log("Distance array: ", distances);
}

//used in simulation to get the coordinate given a certain distance from the start (linear search)
function getPointByDistance(dist){
    if (dist < distances[0].dist) return distances[0];
    for (let i=0; i<distances.length-1; i++){
        if (distances[i].dist<=dist && distances[i+1].dist>dist){
            return distances[i];
        }
    }
    return distances[distances.length-1];
}

function generateBackground(){
    for (let i=0; i<300; i++){
        background_circles.push([map(Math.random(), 0, 1, buffer_width, width), map(Math.random(), 0, 1, 0, height), map(Math.random(), 0, 1, 1, 5)])
    }
}
function drawBackground(){//as the name of the function suggests
    push();
    fill(180);
    noStroke();
    for (let circles of background_circles){
        circle(circles[0], circles[1], circles[2]);
    }
    pop();
}


//buttons copy-paste
function init_buttons(){
    addpoint_button(button_addpoint);
    removepoint_button(button_removepoint);
    start_button(button_start);
    stop_button(button_stop);
    reset_button(button_reset);
    step_button(button_step);
    velocity_button(button_velocity);
}

function addpoint_button(x){
    x.locate(20, 85);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Add :D";
    x.textSize = 15;
    x.textFont = font;
    x.stroke = color(0);
    x.strokeWeight = 3; 

    x.onPress = function(){
        if (points.length <= 10){
            new_point_mode = true;
        }
        else{
            alert_list.push(new PopUp("Is 10 points not enough for you :", 3000));
        }
    }
}

function removepoint_button(x){
    x.locate(20, 120);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Remove";
    x.textSize = 15;    
    x.textFont = font;
    x.stroke = color(0);
    x.strokeWeight = 3; 

    x.onPress = function(){
        if (points.length >= 5){
            points.pop();
            calc();
        }
        else{
            alert_list.push(new PopUp("You can't have less than 4 points!", 3000));
        }
    }
}

function reset_button(x){
    x.locate(20, 155);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Reset";
    x.textSize = 15;    
    x.textFont = font;
    x.stroke = color(0);
    x.strokeWeight = 3; 

    x.onPress = function(){
        obj.started = false;
        let points = [
            [150, 50],
            [200, 100],
            [250, 50],
            [300, 100],
            [350, 50],
            [400, 100]
        ];
        calc();
    }
}

function start_button(x){
    x.locate(20, 230);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Start";
    x.textSize = 15;    
    x.textFont = font;
    x.stroke = color(0);
    x.strokeWeight = 3; 

    x.onPress = function(){
        obj.started = true;
        obj.simulate = true;
    }
}
function stop_button(x){
    x.locate(20, 265);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Stop";
    x.textSize = 15;    
    x.textFont = font;
    x.stroke = color(0);
    x.strokeWeight = 3; 

    x.onPress = function(){
        obj.started = false;
    }
}
function step_button(x){
    x.locate(20, 300);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Step";
    x.textSize = 15;    
    x.textFont = font;
    x.stroke = color(0);
    x.strokeWeight = 3; 

    x.onPress = function(){
        obj.started = true;
        for (let i=0; i<slider_step.value(); i++){
            obj.update();
        }
    }
}
function velocity_button(x){
    x.locate(20, 390);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0,0,0,150);
    x.text = "Velocity";
    x.textSize = 15;    
    x.textFont = font;
    x.stroke = color(0,0,0,150);
    x.strokeWeight = 3; 

    x.onPress = function(){
        if (obj.show_velocity){
            obj.show_velocity = false;
            x.textColor = color(0,0,0,150);
            x.stroke = color(0,0,0,150);
        }
        else{
            obj.show_velocity = true;
            x.textColor = color(0);
            x.stroke = color(0);
        }
    }
}


//dragging functionality
function mousePressed(){
    current_hover = null;
    let arr = [];
    for (let i=0; i<points.length; i++){
        let dist = math.sqrt((points[i][0]-mouseX)**2+(points[i][1]-mouseY)**2);
        arr.push({dist: dist, index: i});
    }
    arr.sort((a, b) => a.dist-b.dist); //finds the closest point to the mouse
    if (arr[0].dist<15){
        current_hover = arr[0].index; //sets it as the point being dragged (i.e. follows mouse position)
    }  
}

function mouseMoved(){ //used when a new point is being added
    if (current_hover != null){
        points[current_hover] = [constrain(mouseX, buffer_width, width), constrain(mouseY, 0, height)]; //ensures that the point remains within the frame
    }
}

function mouseDragged(){
    if (current_hover != null){ //if a point is currently being dragged
        points[current_hover] = [constrain(mouseX, buffer_width, width), constrain(mouseY, 0, height)]; //ensures that the point remains within the frame
    }
}

function mouseReleased(){
    if (current_hover != null){
        calc();
    }
    current_hover = null; //point no longer being dragged
}