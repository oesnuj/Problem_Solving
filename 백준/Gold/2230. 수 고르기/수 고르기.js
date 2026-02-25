const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [n, m] = input[0].split(' ').map(Number);
const a = input.slice(1).map(Number);

a.sort((a, b) => a - b);

let st = 0;
let en = 0;
let answer = Infinity;

while (st < n && en < n) {
  let tmp = a[en] - a[st];
  if (tmp >= m) {
    answer = Math.min(answer, tmp);
    st++;
  } else {
    en++;
  }
  if (answer === m) break;
}
console.log(answer);