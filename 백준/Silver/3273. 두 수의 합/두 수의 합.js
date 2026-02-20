const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = input[1].split(' ').map(Number);
const x = +input[2];

let cnt = 0;

for (let i = 0; i < n; i++) {
  for (let j = i + 1; j < n; j++) {
    if (a[i] + a[j] === x) cnt++;
  }
}
console.log(cnt);