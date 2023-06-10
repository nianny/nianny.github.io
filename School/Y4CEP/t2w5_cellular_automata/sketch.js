let gridSize = 200;
let cellSize = 5;
let grid;
let rule = 90; // Rule in decimal
let c;

function setup() {
    // frameRate(1)
    noStroke();
    c = createCanvas(gridSize * cellSize, gridSize * cellSize);
    grid = new Array(gridSize).fill(0);
    grid[Math.floor(gridSize / 2)] = 1; // Set the center cell to alive
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
        let left=0, center, right=0;
        if (i!=0){
            left = grid[(i - 1 + gridSize) % gridSize];
        }
        if (i != gridSize-1){
            right = grid[(i + 1) % gridSize];
        }
        center = grid[i];
        newGrid[i] = applyRule(center, left, right);
    }

    grid = newGrid;
}

function draw() {
    background(255);
  
    for (let row = 0; row < gridSize; row++) {
        for (let col = 0; col < gridSize; col++) {
            if (grid[col] === 1) {
                fill(0);
            } else {
                fill(255);
            }
                rect(col * cellSize, row * cellSize, cellSize, cellSize);
        }
        updateGrid();
    }
    // saveCanvas(c, str(rule), 'jpg')
    noLoop(); // Remove this line if you want to animate the automaton continuously
}