const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [R, C] = input[0].split(' ').map(Number);
const grid = input.slice(1);
const board = Array.from({ length: R }, () => Array(C).fill(-2));
const fire = [];
let J, F;

for (let i = 0; i < R; i++) {
  for (let j = 0; j < C; j++) {
    if (grid[i][j] === 'J') J = [i, j];
    if (grid[i][j] === 'F') fire.push([i, j]);
    if (grid[i][j] === '#') {
      board[i][j] = -1;
    }
  }
}

const [jx, jy] = J;

const Jboard = board.map((row) => [...row]);

const dirs = [
  [1, 0],
  [0, 1],
  [-1, 0],
  [0, -1],
];

const queue = [];
let head = 0;
for (const [fx, fy] of fire) {
  queue.push([fx, fy]);
  board[fx][fy] = 0;
}

while (head < queue.length) {
  const [x, y] = queue[head++];

  for (const [dx, dy] of dirs) {
    const nx = x + dx;
    const ny = y + dy;
    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
    if (board[nx][ny] === -1 || board[nx][ny] !== -2) continue;
    board[nx][ny] = board[x][y] + 1;
    queue.push([nx, ny]);
  }
}

queue.push([jx, jy]);
Jboard[jx][jy] = 0;

while (head < queue.length) {
  const [x, y] = queue[head++];

  for (const [dx, dy] of dirs) {
    const nx = x + dx;
    const ny = y + dy;
    if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
      console.log(Jboard[x][y] + 1);
      return;
    }
    if (Jboard[nx][ny] === -1 || Jboard[nx][ny] !== -2) continue;

    // 이동시간이 불의 전파보다 느렸다면 해당 칸은 접근 불가능
    if (board[nx][ny] !== -2 && Jboard[x][y] + 1 >= board[nx][ny]) continue;
    Jboard[nx][ny] = Jboard[x][y] + 1;
    queue.push([nx, ny]);
  }
}

console.log('IMPOSSIBLE');
