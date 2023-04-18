let gridSize = 50;
let cellSize = 10;
let grid;
let rule = 90; // Rule in decimal
let c;
let currentRow = 0;
let translate_y=0;
let fpm = 5; // frames per movement
let fps = 100; // frames per second

function setup() {
    frameRate(fps);
    noStroke();
    c = createCanvas(gridSize * cellSize, gridSize * cellSize);
    restart();
}

function applyRule(currentState, leftNeighbor, rightNeighbor) {
    let binaryString = leftNeighbor.toString() + currentState.toString() + rightNeighbor.toString();
    let index = parseInt(binaryString, 2);
    let ruleBinary = rule.toString(2).padStart(8, "0");
  
    return parseInt(ruleBinary[7 - index], 10);
}
  
function updateGrid() {
    let newGrid = new Array(gridSize).fill(0);

    for (let i = 0; i < gridSize; i++) {
        let left = grid[grid.length-1][(i - 1 + gridSize) % gridSize];
        let center = grid[grid.length-1][i];
        let right = grid[grid.length-1][(i + 1) % gridSize];
        newGrid[i] = applyRule(center, left, right);
    }

    grid.push(newGrid);
    if (grid.length > gridSize){
        grid=grid.slice(1);
    }
}

function draw() {
    background(255);

    
    if (currentRow > gridSize){
        translate(0, -(translate_y-1)%fpm/fpm*cellSize);
    }
  
    for (let row = 0; row < grid.length; row++) {
        for (let col = 0; col < gridSize; col++) {
            if (grid[row][col] === 1) {
                fill(0);
            } else {
                fill(255);
            }
                rect(col * cellSize, row * cellSize, cellSize, cellSize);
        }
    }

    if (translate_y%fpm == 0){
        updateGrid();

        currentRow++;
    }
    
    translate_y++;
    console.log(grid);
}

function restart(){
    grid = [new Array(gridSize).fill(0)];
    grid[0][Math.floor(gridSize / 2)] = 1; // Set the center cell to alive
}