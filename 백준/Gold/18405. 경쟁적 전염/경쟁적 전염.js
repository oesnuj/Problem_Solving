const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, K] = input[0].split(' ').map(Number);
grid = input.slice(1, N + 1).map((e) => e.split(' ').map(Number));
const [S, X, Y] = input[N + 1].split(' ').map(Number);

const queue = [];
let head = 0;
for (let x = 0; x < N; x++) {
  for (let y = 0; y < N; y++) {
    if (grid[x][y] > 0) {
      queue.push([grid[x][y], x, y]);
    }
  }
}

const ways = [
  [-1, 0],
  [0, -1],
  [1, 0],
  [0, 1],
];

queue.sort((a, b) => a[0] - b[0]);

let time = 0;
while (head < queue.length && time < S) {
  let sizes = queue.length - head;
  for (let i = 0; i < sizes; i++) {
    const [virus, x, y] = queue[head++];
    const num = grid[x][y];

    for (const [dx, dy] of ways) {
      const nx = x + dx;
      const ny = y + dy;
      if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] === 0) {
        queue.push([virus, nx, ny]);
        grid[nx][ny] = num;
      }
    }
  }
  time++;
}
console.log(grid[X - 1][Y - 1]);
