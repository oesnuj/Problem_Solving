const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');
const [N, M] = input[0].split(' ').map(Number);
const grid = [];
const visited = Array.from({ length: N }, () => Array.from({ length: M }, () => Array(2)));
const dirs = [
  [0, 1],
  [1, 0],
  [0, -1],
  [-1, 0],
];
for (let i = 1; i <= N; i++) {
  grid.push(input[i].trim().split('').map(Number));
}

const queue = [[0, 0, 0]];
let head = 0;
visited[0][0][0] = 1;

while (head < queue.length) {
  const [x, y, breakCnt] = queue[head++];

  if (x === N - 1 && y === M - 1) {
    console.log(visited[x][y][breakCnt]);
    return;
  }
  for (const [dx, dy] of dirs) {
    const nx = x + dx;
    const ny = y + dy;
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

    let newBreakCnt = breakCnt;
    if (grid[nx][ny] === 1) {
      if (breakCnt === 1) continue;
      newBreakCnt += 1;
    }

    if (visited[nx][ny][newBreakCnt]) continue;

    visited[nx][ny][newBreakCnt] = visited[x][y][breakCnt] + 1;
    queue.push([nx, ny, newBreakCnt]);
  }
}

console.log(-1);