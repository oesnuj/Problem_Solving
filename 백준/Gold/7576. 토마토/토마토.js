const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [M, N] = input[0].split(' ').map(Number);
const grid = input.slice(1).map((e) => e.split(' ').map(Number));

const RIPE = 1;
const UNRIPE = 0;

const ways = [
  [-1, 0],
  [0, -1],
  [1, 0],
  [0, 1],
];

const queue = [];
let head = 0;

let allRipe = true;
for (let x = 0; x < N; x++) {
  for (let y = 0; y < M; y++) {
    if (grid[x][y] === RIPE) {
      queue.push([x, y, 0]);
    } else if (grid[x][y] === UNRIPE) {
      allRipe = false;
    }
  }
}

if (allRipe) {
  console.log(0);
  return;
}

let answer = 0;
while (head < queue.length) {
  const [x, y, day] = queue[head++];
  answer = day;

  for (const [dx, dy] of ways) {
    const nx = x + dx;
    const ny = y + dy;

    if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] === UNRIPE) {
      grid[nx][ny] = RIPE;
      queue.push([nx, ny, day + 1]);
    }
  }
}

for (let x = 0; x < N; x++) {
  for (let y = 0; y < M; y++) {
    if (grid[x][y] === UNRIPE) {
      console.log(-1);
      return;
    }
  }
}

console.log(answer);
