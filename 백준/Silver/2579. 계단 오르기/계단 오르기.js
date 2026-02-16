const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n')
  .map(Number);

const N = input[0];
const stairs = [0, ...input.slice(1)];
const dp = Array.from({ length: N + 1 }, () => Array(3).fill(0));

dp[1][1] = stairs[1];
if (N >= 2) {
  dp[2][1] = stairs[2];
  dp[2][2] = stairs[1] + stairs[2];
}

for (let i = 3; i <= N; i++) {
  dp[i][1] = Math.max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
  dp[i][2] = dp[i - 1][1] + stairs[i];
}

console.log(Math.max(dp[N][1], dp[N][2]));