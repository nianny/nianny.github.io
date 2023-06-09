let mode = "draw";
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
    [50, 50],
    [100, 100],
    [150, 50],
    // [200, 100],
    // [250, 50],
    // [300, 100],
]
let c_matrix = [];

let inverse_of_141;

let b_matrix = [];
let controls = [];

let beziers = [];
let current_hover = null;

function preload(){
    inverse_of_141 = loadJSON('inverse.json');
    console.log(inverse_of_141);
}

function setup() {
    createCanvas(400, 400);
}

function draw() {
    background(220);
    noStroke();
    calc();
    
    for (let point of points){
        fill(0);
        circle(point[0], point[1], 10);
        fill(0,0,0,50);
        circle(point[0], point[1], 20);
    }

    noFill();
    stroke("black");
    strokeWeight(2);
    for (let i=0; i<beziers.length; i++){
        bezier(beziers[i][0][0], beziers[i][0][1], beziers[i][1][0], beziers[i][1][1], beziers[i][2][0], beziers[i][2][1], beziers[i][3][0], beziers[i][3][1]);
    }
}

function calc(){
    c_matrix = [];
    b_matrix = [];
    beziers = [];
    distances = [];
    for (let i=1; i<points.length-1; i++){
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
    b_matrix.push([points[0][0], points[0][1]]);
    let b_part = math.multiply(inverse_of_141[points.length-2], c_matrix)
    for (let i=0; i<b_part.length; i++){
        b_matrix.push(b_part[i]);
    }
    b_matrix.push([points[points.length-1][0], points[points.length-1][1]]);

   

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

//dragging functionality
function mousePressed(){
    let arr = [];
    for (let i=0; i<points.length; i++){
        let dist = math.sqrt((points[i][0]-mouseX)**2+(points[i][1]-mouseY)**2);
        arr.push({dist: dist, index: i});
    }
    arr.sort((a, b) => a.dist-b.dist); //finds the closest point to the mouse
    if (arr[0].dist<20){
        current_hover = arr[0].index;
    }

    
}

function mouseDragged(){
    if (current_hover != null){ //if a point is currently being dragged
        points[current_hover] = [mouseX, mouseY];
    }
    console.log(current_hover);
}

function mouseReleased(){
    current_hover = null;
}