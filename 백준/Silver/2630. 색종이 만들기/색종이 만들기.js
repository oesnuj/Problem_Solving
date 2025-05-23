const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const N = +input.shift();
const arr = input.map((v) => v.split(' ').map(Number));
let white = 0, blue = 0;

function recursion(r, c, n) {
  for (let i = r; i < r + n; i++) {
    for (let j = c; j < c + n; j++) {
      if (arr[i][j] !== arr[r][c]) {
        let half = n / 2;
        recursion(r, c, half);
        recursion(r, c + half, half);
        recursion(r + half, c, half);
        recursion(r + half, c + half, half);
        return;
      }
    }
  }
  if (arr[r][c]) blue++;
  else white++;
}

function main() {
  recursion(0, 0, N);
  console.log(white);
  console.log(blue);
}

main();