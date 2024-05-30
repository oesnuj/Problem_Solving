const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().split('\n');
const board = input.slice(0, 5).map(line => line.split(' ').slice(0, 5).map(Number));
const says = input.slice(5, 10).map(line => line.split(' ').map(Number)).flat();
const BINGO_SIZE = 5;

const changeBingo = (target) => {
    for (let i = 0; i < BINGO_SIZE; i++) {
        for (let j = 0; j < BINGO_SIZE; j++) {
            if (board[i][j] == target) {
                board[i][j] = 0;
                return;
            }
        }
    }
}


const checkBingo = () => {
    let bingoCnt = 0;
    for (let i = 0; i < BINGO_SIZE; i++)  //가로, 세로 빙고 확인
    {
        let horizontal = 0, vertical = 0;
        for (let j = 0; j < BINGO_SIZE; j++){
            if (!board[i][j])
                horizontal++;
            if (!board[j][i])
                vertical++;
        }
        if (horizontal == BINGO_SIZE) bingoCnt++;
        if (vertical == BINGO_SIZE) bingoCnt++;
    }													

    let right_diagonal = 0, left_diagonal = 0;
    for (let i = 0; i < BINGO_SIZE; i++) //대각선 2개 빙고 확인
    {
        if (!board[i][i]) right_diagonal++;
        if (!board[i][BINGO_SIZE - i - 1]) left_diagonal++;
    }
    if (right_diagonal == BINGO_SIZE) bingoCnt++;
    if (left_diagonal == BINGO_SIZE) bingoCnt++;

    return bingoCnt;

}

let sayCnt = 0;
for (let i = 0; i < BINGO_SIZE * BINGO_SIZE; i++){
            sayCnt++;
            changeBingo(says[i]);
            if (checkBingo() >= 3) {
                console.log(sayCnt);
                return;
            }
}