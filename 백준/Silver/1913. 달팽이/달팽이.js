const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');
const n = +input[0];
const target = +input[1];
let targetPoint = [];
let currentRow = Math.floor(n/2);
let currentCol = Math.floor(n/2);

let board = Array.from({length : n}, () => Array(n).fill(0));
let currentSize = 3;

let i = 1;
board[currentRow][currentCol] = i++;
checkPoint(currentRow, currentCol)
while(currentSize <= n){
    currentRow -= 1; //위로 1칸
    board[currentRow][currentCol] = i++;
    checkPoint(currentRow, currentCol)
    for(let j = 0; j< currentSize-2; j++){ //오른쪽으로
        currentCol += 1;
        board[currentRow][currentCol] = i++;
        checkPoint(currentRow, currentCol)
    }

    for(let j = 0; j< currentSize-1; j++){ //아래로
        currentRow += 1;
        board[currentRow][currentCol] = i++;
        checkPoint(currentRow, currentCol)
    }
    for(let j = 0; j< currentSize-1; j++){ //왼쪽으로
        currentCol -= 1;
        board[currentRow][currentCol] = i++;
        checkPoint(currentRow, currentCol)
    }
    for(let j = 0; j< currentSize-1; j++){ //위로
        currentRow -= 1;
        board[currentRow][currentCol] = i++;
        checkPoint(currentRow, currentCol)
    }
    currentSize += 2;
}
printBoard();
console.log(`${targetPoint[0]} ${targetPoint[1]}`);

function printBoard(){
    for(let k = 0; k<n; k++){
            console.log(board[k].join(" "));
        }
}

function checkPoint(r, c){
    if(board[r][c] != target)
        return;
    else
        targetPoint =[r+1, c+1];
}