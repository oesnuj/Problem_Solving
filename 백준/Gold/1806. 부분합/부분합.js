const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [n, s] = input[0].split(' ').map(Number);
const a = input[1].split(' ').map(Number);

let en = 0;
let sum = a[0];
let answer = n + 1;

for (let st = 0; st < n; st++) {
  while (en < n && sum < s) {
    en++;
    if (en !== n) sum += a[en];
  }
  if (en === n) break;
  answer = Math.min(answer, en - st + 1);
  sum -= a[st];
}

console.log(answer === n + 1 ? 0 : answer);