const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = [0, ...input[1].split(' ').map(Number)];
const dp = Array(n + 1).fill(0);
dp[1] = 1;

for (let i = 2; i <= n; i++) {
  let max = 0;
  for (let x = 1; x < i; x++) {
    if (a[x] < a[i]) max = Math.max(max, dp[x]);
  }
  dp[i] = max + 1;
}

console.log(Math.max(...dp));