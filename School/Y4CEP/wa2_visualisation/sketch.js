let iterations = 30;
let scope;
let hue;
let scale = 100;
let resolution = 20;
let hmm = 1;
let points = [];
let size;
let recalculating = true;
let button_recalculate;
let button_reset;



let canvas;

let a_time = 0;
let b_time = 0;
let calc_time = 0;

let calcs = 0;
let hover_key = null;


let img;
function setup() {
    canvas = createCanvas(windowWidth, windowHeight); //fullscreen
    rectMode(CORNER);
    noStroke();
    scope = {a: math.complex(1, 0), b: math.complex(-1/2, math.sqrt(3)/2), c: math.complex(-1/2, -math.sqrt(3)/2)} //initial roots set to roots of unity :D
    hue = {a: color("#1686B6"), b:color("#05B3B3"), c:color("#74586D")}; //defines the three colours used
    textFont("Pangolin", 15);
    textAlign(LEFT, TOP);

    //initialise buttons
    button_recalculate = new Clickable();
    button_reset = new Clickable();

    recalculate_button(button_recalculate, 10, 90);
    reset_button(button_reset, 10,120);
}



function draw(){
    background(220);

    if (recalculating){
        recalculate();
    }
    
    
    //redraws the image every frame
    image(img, 0, 0, width, height)

    //draws out the roots of the current fractal
    for (const root of Object.values(scope)){
        fill(0,0,0);
        let coord = gridtopixel(root.re, root.im);
        circle(coord.x, coord.y, 5);
        fill(0,0,0,50);
        circle(coord.x, coord.y, 10);
    }

    //draws out the text that shows what the roots are
    fill(0);
    text("Roots:", 10, 10);
    for (const root of Object.values(scope)){
        text(root.re.toFixed(2) + " + " + root.im.toFixed(2) + "i", 10, 30 + 20*Object.values(scope).indexOf(root));
    }

    button_recalculate.draw();
    button_reset.draw();
}

function gridtopixel(x_co,y_co){
    return {x: x_co*scale+width/2, y: -(y_co*scale)+height/2};
}

function pixeltogrid(x,y){
    return math.complex((x-width/2)/scale, -(y-height/2)/scale);
}
function comp(a,b){
    if (a.dist < b.dist) {
        return -1;
    }
    if (a.dist > b.dist) {
        return 1;
    }
}

function val(x){
    return math.multiply(math.multiply(math.subtract(x, scope.a), math.subtract(x, scope.b)), math.subtract(x, scope.c));
}


//calculates the value of P(x)/P'(x), which is used in the Newton-Raphson method to get the value closer to the roots of the polynomial
function eqn(x){
    calcs++;
    let scope_ish = Object.create(scope);
    scope_ish.x = x;

    //finds the current P(x) as well as P'(x)
    let value = val(x);
    let diff = math.complex(0.000001, 0.000001);
    let derivative = math.divide(math.subtract(val(math.add(x, diff)), value), diff);
    let ans = math.divide(value, derivative);
    return ans;
}

function recalculate(){
    calcs = 0;
    let start = performance.now();
    points = [];
    for (let real = -width/2*hmm; real < width/2*hmm; real += resolution){
        console.log(real);
        for (let imaginary = -height/2*hmm; imaginary < height/2*hmm; imaginary += resolution){
            let a = math.complex(real/scale, -imaginary/scale);
        
            for (let i = 0; i < iterations; i++) {
                a = math.subtract(a, eqn(a));
            }

            
            
            let arr = [];
            for (const key of Object.keys(scope)) {
                let diff = math.subtract(scope[key], a);
                let dist = diff.abs();
                arr.push({dist: dist, colour: hue[key]});
            }
            arr.sort(comp);
            points.push({x: real+width/2*hmm, y: imaginary+height/2*hmm, colour: arr[0].colour});
        }
    }

    img = createImage(width*hmm, height*hmm);
    img.loadPixels();
    let s = new Set();
    for (const point of points){
        //due to the setting of resolution, each calculated "pixel" is actually a sqaure of resulution*resolution
        // console.log(point);
        for (let offx = 0; offx < resolution; offx++){
            for (let offy = 0; offy < resolution; offy++){
                if (point.x+offx >= width*hmm || point.y + offy >= height*hmm) continue;
                img.set(point.x+offx, point.y+offy, point.colour);
            }
        }
    }
    img.updatePixels();

    let end = performance.now();
    console.log("Recalculation time:", end - start);
    console.log("Calculations:", calcs);
    recalculating = false;
}

function reset_button(button,x,y){
    button.locate(x,y);
    button.resize(50,25);
    button.cornerRadius = 5;
    button.color = color(0,0,0,0);
    button.textCOlor = color(0);
    button.text = "Reset";
    button.textSize = 15;
    button.textFont = "Pangolin";
    button.stroke = color(0,0,0,150);
    button.onPress = function(){
        scope = {a: math.complex(1, 0), b: math.complex(-1/2, math.sqrt(3)/2), c: math.complex(-1/2, -math.sqrt(3)/2)}
        recalculating = true;
    }
}

function recalculate_button(button,x,y){
    button.locate(x,y);
    button.resize(100,25);
    button.cornerRadius = 5;
    button.color = color(0,0,0,0);
    button.textCOlor = color(0);
    button.text = "Recalculate";
    button.textSize = 15;
    button.textFont = "Pangolin";
    button.stroke = color(0,0,0,150);
    button.onPress = function(){
        // scope = {a: math.complex(1, 0), b: math.complex(-1/2, math.sqrt(3)/2), c: math.complex(-1/2, -math.sqrt(3)/2)}
        recalculating = true;
    }
}


function mousePressed(){
    let arr = [];
    for (const key of Object.keys(scope)){
        let pos = gridtopixel(scope[key].re, scope[key].im);
        let dist = math.sqrt((pos.x-mouseX)*(pos.x-mouseX)+(pos.y-mouseY)*(pos.y-mouseY));
        arr.push({dist: dist, key: key});
    }
    
    arr.sort(comp);
    if (arr[0].dist < 10){
        console.log(arr);
        hover_key = arr[0].key;  
    }
}

function mouseDragged(){
    if (hover_key){
        scope[hover_key] = pixeltogrid(mouseX, mouseY);
        console.log(scope);
    }
}

function mouseReleased(){
    hover_key = null;
}


