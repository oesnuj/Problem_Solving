const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n')
  .map(Number);

const [n, ...w] = input;

w.sort((a, b) => a - b);
let answer = 0;
for (let k = 1; k <= n; k++) {
  answer = Math.max(answer, w[n - k] * k);
}
console.log(answer);