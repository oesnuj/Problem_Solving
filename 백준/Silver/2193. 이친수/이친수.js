const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const dp = Array.from({ length: n + 1 });

dp[1] = 1n;
dp[2] = 1n;

for (let i = 3; i <= n; i++) {
  dp[i] = dp[i - 2] + dp[i - 1];
}

console.log(dp[n].toString());