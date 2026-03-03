const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const dp = Array(N + 1);
dp[1] = 1;
dp[2] = 2;

for (let i = 3; i <= N; i++) {
  dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
}

console.log(dp[N]);