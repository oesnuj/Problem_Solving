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
const output = []; // ← 출력 버퍼

while (T--) {
  const l = +input[idx++];
  const [startX, startY] = input[idx++].split(' ').map(Number);
  const [endX, endY] = input[idx++].split(' ').map(Number);

  output.push(bfs(l, startX, startY, endX, endY));
}

console.log(output.join('\n'));

function bfs(l, startX, startY, endX, endY) {
  if (startX === endX && startY === endY) return 0;

  let time = 0;
  let head = 0;
  const qx = [startX];
  const qy = [startY];
  const visited = Array.from({ length: l }, () => Array(l).fill(false));
  visited[startX][startY] = true;

  while (head < qx.length) {
    const sizes = qx.length - head;

    for (let i = 0; i < sizes; i++) {
      const x = qx[head];
      const y = qy[head];
      head++;

      if (x === endX && y === endY) {
        return time;
      }

      for (const [dx, dy] of moves) {
        const nx = x + dx;
        const ny = y + dy;

        if (0 <= nx && nx < l && 0 <= ny && ny < l && !visited[nx][ny]) {
          qx.push(nx);
          qy.push(ny);
          visited[nx][ny] = true;
        }
      }
    }
    time++;
  }
}
