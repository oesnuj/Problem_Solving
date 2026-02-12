const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const array = input.slice(1);
const grid = array.map((e) => e.split('').map(Number));
const answer = [];

function check(n, r, c) {
  for (let i = r; i < r + n; i++) {
    for (let j = c; j < c + n; j++) {
      if (grid[r][c] !== grid[i][j]) return false;
    }
  }
  return true;
}

function recursion(n, r, c) {
  if (n === 1) {
    answer.push(grid[r][c]);
    return;
  }

  if (check(n, r, c)) {
    answer.push(grid[r][c]);
    return;
  }
  let val = Math.trunc(n / 2);
  answer.push('(');
  recursion(val, r, c);
  recursion(val, r, c + val);
  recursion(val, r + val, c);
  recursion(val, r + val, c + val);
  answer.push(')');
}

recursion(n, 0, 0);
console.log(answer.join(''));
