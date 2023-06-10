let iterations = 10;
let scope;
let hue;
let scale = 100;
let resolution = 10;
let points = [];
let size;
let recalculating = true;
let button_recalculate;
let button_reset;

let slider_iterations;
let slider_scale;
let slider_resolution;


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

    //intialise sliders
    slider_iterations = createSlider(5, 50, iterations, 1);
    slider_scale = createSlider(50, 200, scale, 10);
    slider_resolution = createSlider(1, 20, resolution, 1);
    sliders(slider_iterations, 100, 90);
    sliders(slider_scale, 100, 120);
    sliders(slider_resolution, 100, 150);

    //initialise buttons
    button_recalculate = new Clickable();
    button_reset = new Clickable();

    recalculate_button(button_recalculate, 10, 180);
    reset_button(button_reset, 10,210);
}



function draw(){
    background(220);

    iterations = slider_iterations.value();
    scale = slider_scale.value();
    resolution = slider_resolution.value();

    //calculates entire image
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

    //draws text around sliders
    text("Iterations: " + iterations, 10, 95);
    text("Scale: " + scale, 10, 125);
    text("Resolution: " + resolution, 10, 155);

    //draws buttons
    button_recalculate.draw();
    button_reset.draw();
}

//conversion between complex values on the graph and positions values on the canvas
function gridtopixel(x_co,y_co){
    return {x: x_co*scale+width/2, y: -(y_co*scale)+height/2};
}

function pixeltogrid(x,y){
    return math.complex((x-width/2)/scale, -(y-height/2)/scale);
}

//comparator to sort by smallest distance
function comp(a,b){
    if (a.dist < b.dist) {
        return -1;
    }
    if (a.dist > b.dist) {
        return 1;
    }
}

//(x-a)(x-b)(x-c), cubic eqn for 3 roots
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
    //loops through every pixel and finds point after x interations
    for (let real = -width/2; real < width/2; real += resolution){
        for (let imaginary = -height/2; imaginary < height/2; imaginary += resolution){
            let a = math.complex(real/scale, -imaginary/scale);
        
            for (let i = 0; i < iterations; i++) {
                a = math.subtract(a, eqn(a));
            }

            
            //finds closest root and assigns colour
            let arr = [];
            for (const key of Object.keys(scope)) {
                let diff = math.subtract(scope[key], a);
                let dist = diff.abs();
                arr.push({dist: dist, colour: hue[key]});
            }
            arr.sort(comp);
            points.push({x: real+width/2, y: imaginary+height/2, colour: arr[0].colour});
        }
    }


    //draws otno image
    img = createImage(width, height);
    img.loadPixels();
    let s = new Set();
    for (const point of points){
        //due to the setting of resolution, each calculated "pixel" is actually a sqaure of resulution*resolution
        for (let offx = 0; offx < resolution; offx++){
            for (let offy = 0; offy < resolution; offy++){
                if (point.x+offx >= width || point.y + offy >= height) continue;
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

//settings for buttons
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
        //reset roots and slider values
        scope = {a: math.complex(1, 0), b: math.complex(-1/2, math.sqrt(3)/2), c: math.complex(-1/2, -math.sqrt(3)/2)}
        slider_iterations.value(20); //ty yunze :D
        slider_scale.value(100);
        slider_resolution.value(10);
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

//set settings for sliders
function sliders(slider, x, y){
    slider.position(x, y);
    slider.style('width', '50px');
}

//handles the moving and changing of roots
function mousePressed(){
    let arr = [];
    for (const key of Object.keys(scope)){
        let pos = gridtopixel(scope[key].re, scope[key].im);
        let dist = math.sqrt((pos.x-mouseX)*(pos.x-mouseX)+(pos.y-mouseY)*(pos.y-mouseY));
        arr.push({dist: dist, key: key});
    }
    
    arr.sort(comp);
    if (arr[0].dist < 10){
        hover_key = arr[0].key;  
    }
}

function mouseDragged(){
    if (hover_key){
        scope[hover_key] = pixeltogrid(mouseX, mouseY);
    }
}

function mouseReleased(){
    hover_key = null;
}


