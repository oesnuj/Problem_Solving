const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const board = Array.from({ length: n }, () => Array(2 * n - 1).fill(' '));

function recursion(n, r, c) {
  if (n === 3) {
    board[r][c] = '*';
    board[r + 1][c - 1] = '*';
    board[r + 1][c + 1] = '*';
    board[r + 2][c - 2] = '*';
    board[r + 2][c - 1] = '*';
    board[r + 2][c] = '*';
    board[r + 2][c + 1] = '*';
    board[r + 2][c + 2] = '*';
    return;
  }

  const half = Math.trunc(n / 2);
  recursion(half, r, c);
  recursion(half, r + half, c - half);
  recursion(half, r + half, c + half);
}

recursion(n, 0, n - 1);

console.log(board.map((row) => row.join('')).join('\n'));