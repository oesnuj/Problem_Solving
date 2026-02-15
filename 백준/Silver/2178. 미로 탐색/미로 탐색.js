const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const board = [];
for (let i = 1; i <= N; i++) {
  board.push(input[i].split('').map(Number));
}
const dirs = [
  [1, 0],
  [-1, 0],
  [0, 1],
  [0, -1],
];

const queue = [[0, 0]];
let head = 0;

while (head < queue.length) {
  const [x, y] = queue[head++];

  for (const [dx, dy] of dirs) {
    const nx = x + dx;
    const ny = y + dy;
    if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] !== 1) continue;
    queue.push([nx, ny]);
    board[nx][ny] = board[x][y] + 1;
  }
}

console.log(board[N - 1][M - 1]);
