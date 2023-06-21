let mode = "draw";
let buffer_width = 100;
let new_point_mode = false;

let background_circles = [];
// let points = [
//     [2, 16.1],
//     [5, 18],
//     [10, 16.8],
//     [15, 17.2],
//     [20, 16.8],
//     [25, 22.1]
// ]
let distances = [];
let points = [
    // [50, 50],
    // [100, 100],
    [150, 50],
    [200, 100],
    [250, 50],
    [300, 100],
]
let c_matrix = [];

let inverse_of_141;

let b_matrix = [];
let controls = [];

let beziers = [];
let current_hover = null;

let alert_list = []; //custom alerts???

//buttons
let button_addpoint;
let button_removepoint;



function preload(){
    inverse_of_141 = loadJSON('inverse.json'); //loads precomputed matrix inverse
    console.log(inverse_of_141);
}

function setup() {
    createCanvas(windowWidth, windowHeight);
    generateBackground();

    textFont("Pangolin", 15);
    button_addpoint = new Clickable();
    button_removepoint = new Clickable();
    init_buttons();

    console.log(button_addpoint.textFont)
    alert_list.push(new PopUp("This is a test", 100));
    
}

function draw() {
    background(220);
    drawBackground();

    noStroke();
    calc();
    fill("#AFBED1");
    rect(0,0, buffer_width, height);

    push();
    stroke(0);
    fill(0);
    textSize(20);
    textAlign(CENTER, CENTER);
    text("Controls", 50, 50);
    pop();

    for (let point of points){
        fill(0);
        circle(point[0], point[1], 10);
        fill(0,0,0,50);
        circle(point[0], point[1], 20);
    }
    
    // for (let i=0; i<b_matrix.length; i++){
    //     fill("red");
    //     circle(b_matrix[i][0], b_matrix[i][1], 10);
    // }

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

    button_addpoint.draw();
    button_removepoint.draw();

    for (let i=0; i<alert_list.length; i++){
        alert_list[i].show(width-210, 10+60*i);
    }
    // noLoop();
}

function calc(){
    c_matrix = [];
    b_matrix = [];
    beziers = [];
    distances = [];
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
    // console.log(c_matrix);
    b_matrix.push(points[0]);
    let b_part = math.multiply(inverse_of_141[points.length-2], c_matrix)
    // console.log(b_part);
    for (let i=0; i<b_part.length; i++){
        b_matrix.push(b_part[i]);
    }
    b_matrix.push(points[points.length-1]);


    for (let i=0; i<points.length-1; i++){
        beziers.push([points[i], [1/3*b_matrix[i+1][0]+2/3*b_matrix[i][0], 1/3*b_matrix[i+1][1]+2/3*b_matrix[i][1]], [2/3*b_matrix[i+1][0]+1/3*b_matrix[i][0], 2/3*b_matrix[i+1][1]+1/3*b_matrix[i][1]], points[i+1]]);
    }
    let total_dist=0;
    let prev_x = beziers[0][0][0];
    let prev_y = beziers[0][0][1];
    for (let i=0; i<beziers.length-1; i++){
        for (let t=0; t<=1; t+=0.01){
            let x = (1-t)**3*beziers[i][0][0]+3*(1-t)**2*t*beziers[i][1][0]+3*(1-t)*t**2*beziers[i][2][0]+t**3*beziers[i][3][0]; // wow github copilot wrote this ish and i checked it and it seems legit
            let y = (1-t)**3*beziers[i][0][1]+3*(1-t)**2*t*beziers[i][1][1]+3*(1-t)*t**2*beziers[i][2][1]+t**3*beziers[i][3][1];

            total_dist += math.sqrt((x-prev_x)**2+(y-prev_y)**2);
            prev_x = x;
            prev_y = y;
            distances.push({dist: total_dist, x: x, y: y});
        }
    }
}

function getPointByDistance(dist){
    for (let i=0; i<distances.length-1; i++){
        if (distances[i].dist<dist && distances[i+1].dist>dist){
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
        // console.log(map(Math.random(), 0, 1, buffer_width, width), map(Math.random(), 0, 1, 0, height), map(Math.random()), 0, 1, 1, 5);
        circle(circles[0], circles[1], circles[2]);
    }
    pop();
}

function init_buttons(){
    addpoint_button(button_addpoint);
    removepoint_button(button_removepoint);
}

function addpoint_button(x){
    x.locate(20, 100);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Add :D";
    x.textSize = 15;    
    x.textFont = "Pangolin";
    x.stroke = color(0,0,0,150);
    x.strokeWeight = 3; 

    x.onPress = function(){
        new_point_mode = true;
    }
}

function removepoint_button(x){
    x.locate(20, 150);
    x.resize(60, 30);
    x.cornerRadius = 5;
    x.color = color(0,0,0,0);
    x.textColor = color(0);
    x.text = "Remove";
    x.textSize = 15;    
    x.textFont = "Pangolin";
    x.stroke = color(0,0,0,150);
    x.strokeWeight = 3; 

    x.onPress = function(){
        if (points.length >= 5){
            points.pop();
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
    if (arr[0].dist<20){
        current_hover = arr[0].index; //sets it as the point being dragged (i.e. follows mouse position)
    }  
}

function mouseMoved(){ //used when a new point is being added
    if (current_hover != null){
        points[current_hover] = [constrain(mouseX, buffer_width, width), constrain(mouseY, 0, height)]; //ensures that the point remains within the frame
    }
    console.log(current_hover);
}

function mouseDragged(){
    if (current_hover != null){ //if a point is currently being dragged
        points[current_hover] = [constrain(mouseX, buffer_width, width), constrain(mouseY, 0, height)]; //ensures that the point remains within the frame
    }
    console.log(current_hover);
}

function mouseReleased(){
    current_hover = null; //point no longer being dragged
    console.log(current_hover);
}