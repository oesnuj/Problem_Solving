const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [R, C] = input[0].split(' ').map(Number);
const grid = input.slice(1);

const WALL = -1;
const UNVISITED = -2;

const fireTime = Array.from({ length: R }, () => Array(C).fill(UNVISITED));
const personTime = Array.from({ length: R }, () => Array(C).fill(UNVISITED));

const fires = [];
let start;

for (let i = 0; i < R; i++) {
  for (let j = 0; j < C; j++) {
    if (grid[i][j] === 'J') start = [i, j];
    if (grid[i][j] === 'F') fires.push([i, j]);
    if (grid[i][j] === '#') {
      fireTime[i][j] = WALL;
      personTime[i][j] = WALL;
    }
  }
}
const dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]];
const inRange = (x, y) => x >= 0 && x < R && y >= 0 && y < C;

// 불 확산
const fireQueue = [...fires];
fires.forEach(([x, y]) => (fireTime[x][y] = 0));

for (let i = 0; i < fireQueue.length; i++) {
  const [x, y] = fireQueue[i];

  for (const [dx, dy] of dirs) {
    const nx = x + dx,
      ny = y + dy;
    if (!inRange(nx, ny) || fireTime[nx][ny] !== UNVISITED) continue;

    fireTime[nx][ny] = fireTime[x][y] + 1;
    fireQueue.push([nx, ny]);
  }
}

// 지훈이 탈출
const personQueue = [start];
personTime[start[0]][start[1]] = 0;

for (let i = 0; i < personQueue.length; i++) {
  const [x, y] = personQueue[i];

  for (const [dx, dy] of dirs) {
    const nx = x + dx,
      ny = y + dy;

    if (!inRange(nx, ny)) {
      console.log(personTime[x][y] + 1);
      return;
    }

    if (personTime[nx][ny] !== UNVISITED) continue;

    const nextTime = personTime[x][y] + 1;
    if (fireTime[nx][ny] !== UNVISITED && nextTime >= fireTime[nx][ny]) continue;

    personTime[nx][ny] = nextTime;
    personQueue.push([nx, ny]);
  }
}

console.log('IMPOSSIBLE');
