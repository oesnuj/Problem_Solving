const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const arr = [0, ...input[1].split(' ').map(Number)];
const dp = Array(n + 1).fill(-Infinity);

dp[1] = arr[1];

for (let i = 2; i <= n; i++) {
  dp[i] = Math.max(dp[i - 1] + arr[i], arr[i]);
}

console.log(Math.max(...dp));