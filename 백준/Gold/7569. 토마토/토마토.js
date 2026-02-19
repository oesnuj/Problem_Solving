const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [C, R, H] = input[0].split(' ').map(Number);
const board = [];
const dirs = [
  [0, 1, 0],
  [0, -1, 0],
  [0, 0, 1],
  [0, 0, -1],
  [1, 0, 0],
  [-1, 0, 0],
];

let idx = 1;
for (let h = 0; h < H; h++) {
  const layer = [];
  for (let r = 0; r < R; r++) {
    layer.push(input[idx++].split(' ').map(Number));
  }
  board.push(layer);
}

const queue = [];
let head = 0;

for (let h = 0; h < H; h++) {
  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      if (board[h][r][c] === 1) queue.push([h, r, c]);
    }
  }
}

while (head < queue.length) {
  const [h, r, c] = queue[head++];

  for (const [dh, dr, dc] of dirs) {
    const nh = h + dh;
    const nr = r + dr;
    const nc = c + dc;
    if (nh < 0 || nh >= H || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
    if (board[nh][nr][nc] === -1 || board[nh][nr][nc] > 0) continue;
    board[nh][nr][nc] = board[h][r][c] + 1;
    queue.push([nh, nr, nc]);
  }
}

let answer = 0;
for (let h = 0; h < H; h++) {
  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      if (board[h][r][c] === 0) {
        console.log(-1);
        return;
      }
      answer = Math.max(answer, board[h][r][c]);
    }
  }
}

console.log(answer - 1);