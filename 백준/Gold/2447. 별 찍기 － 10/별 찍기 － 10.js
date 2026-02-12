const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const board = Array.from({ length: n }, () => Array(n).fill(' '));

function recursion(n, r, c) {
  if (n === 1) {
    board[r][c] = '*';
    return;
  }

  const size = Math.trunc(n / 3);

  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (i === 1 && j === 1) continue;
      recursion(size, r + size * i, c + size * j);
    }
  }
}

recursion(n, 0, 0);

console.log(board.map((row) => row.join('')).join('\n'));
