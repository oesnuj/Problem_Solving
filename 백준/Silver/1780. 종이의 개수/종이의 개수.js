const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const array = input.slice(1);

const grid = array.map((e) => e.split(' ').map(Number));

const map = new Map();

function recursion(n, r, c) {
  // 색종이 하나
  if (n === 1) {
    map.set(grid[r][c], (map.get(grid[r][c]) ?? 0) + 1);
    return;
  }

  // 모두 같은 색종이가 아니라면 9등분 시키기
  for (let i = r; i < r + n; i++) {
    for (let j = c; j < c + n; j++) {
      if (grid[r][c] !== grid[i][j]) {
        // 9등분
        let val = Math.trunc(n / 3);
        recursion(val, r, c);
        recursion(val, r, c + val);
        recursion(val, r, c + val * 2);
        recursion(val, r + val, c);
        recursion(val, r + val * 2, c);
        recursion(val, r + val, c + val);
        recursion(val, r + val * 2, c + val);
        recursion(val, r + val, c + val * 2);
        recursion(val, r + val * 2, c + val * 2);
        return;
      }
    }
  }

  //모두 같은 색종이라면
  map.set(grid[r][c], (map.get(grid[r][c]) ?? 0) + 1);
}

recursion(n, 0, 0);
console.log([-1, 0, 1].map((k) => map.get(k) ?? 0).join('\n'));
