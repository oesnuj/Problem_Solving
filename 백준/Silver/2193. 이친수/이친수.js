const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const dp = Array.from({ length: n + 1 }, () => Array(2).fill(0n));

dp[1][0] = 0n;
dp[1][1] = 1n;

for (let i = 2; i <= n; i++) {
  dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
  dp[i][1] = dp[i - 1][0];
}

console.log((dp[n][0] + dp[n][1]).toString());