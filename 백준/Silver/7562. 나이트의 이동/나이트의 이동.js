const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const moves = [
  [2, 1],
  [2, -1],
  [-2, 1],
  [-2, -1],
  [1, 2],
  [1, -2],
  [-1, 2],
  [-1, -2],
];

let idx = 0;
let T = +input[idx++];

while (T--) {
  const l = +input[idx++];
  const [startX, startY] = input[idx++].split(' ').map(Number);
  const [endX, endY] = input[idx++].split(' ').map(Number);

  console.log(bfs(l, startX, startY, endX, endY));
}

function bfs(l, startX, startY, endX, endY) {
  let time = 0;
  let head = 0;
  const queue = [[startX, startY]];
  const visited = Array.from({ length: l }, () => Array(l).fill(false));
  visited[startX][startY] = true;

  while (head < queue.length) {
    const sizes = queue.length - head;
    for (let i = 0; i < sizes; i++) {
      const [x, y] = queue[head++];
      if (x === endX && y === endY) {
        return time;
      }
      for (const [dx, dy] of moves) {
        const nx = x + dx;
        const ny = y + dy;
        if (0 <= nx && nx < l && 0 <= ny && ny < l && !visited[nx][ny]) {
          queue.push([nx, ny]);
          visited[nx][ny] = true;
        }
      }
    }
    time++;
  }
}
