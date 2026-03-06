const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const strow = input.slice(1).map(Number);

strow.sort((a, b) => a - b);

for (let i = n - 1; i >= 2; i--) {
  if (strow[i] < strow[i - 1] + strow[i - 2]) {
    console.log(strow[i] + strow[i - 1] + strow[i - 2]);
    return;
  }
}
console.log(-1);