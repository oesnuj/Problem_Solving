const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const dp = Array(n + 1);

dp[1] = 1;
dp[2] = 3;

for (let i = 3; i <= n; i++) {
  dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
}
console.log(dp[n]);