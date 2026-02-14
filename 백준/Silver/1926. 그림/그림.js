const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);

const board = [];

for (let i = 1; i <= N; i++) {
  board.push(input[i].split(' ').map(Number));
}
const isVisited = Array.from({ length: N }, () => Array(M).fill(false));

const dirs = [
  [1, 0],
  [-1, 0],
  [0, 1],
  [0, -1],
];

let cnt = 0;
let area = 0;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (board[i][j] === 0 || isVisited[i][j]) continue;

    const queue = [];
    let head = 0;

    queue.push([i, j]);
    isVisited[i][j] = true;
    let currentArea = 1;

    while (head < queue.length) {
      const [x, y] = queue[head++];
      for (const [dx, dy] of dirs) {
        const nx = x + dx;
        const ny = y + dy;
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || isVisited[nx][ny] || !board[nx][ny]) continue;
        isVisited[nx][ny] = true;
        queue.push([nx, ny]);
        currentArea++;
      }
    }

    if (currentArea > 0) {
      area = Math.max(area, currentArea);
      cnt++;
    }
  }
}

console.log(cnt + '\n' + area);
