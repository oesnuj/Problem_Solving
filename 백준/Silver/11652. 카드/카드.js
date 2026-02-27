const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = [...input.splice(1).map(BigInt)];

a.sort((a, b) => {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
});

let max_num = a[0];
let max_cnt = 1;
let cnt = 1;

for (let i = 1; i < n; i++) {
  if (a[i] === a[i - 1]) cnt++;
  else {
    if (cnt > max_cnt) {
      max_cnt = cnt;
      max_num = a[i - 1];
    }
    cnt = 1;
  }
}

if (cnt > max_cnt) max_num = a[n - 1];

console.log(max_num.toString());