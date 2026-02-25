const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const dp = Array.from({ length: n + 1 }, () => Array(10));

for (let i = 0; i <= 9; i++) {
  if (i === 0) dp[1][i] = 0;
  else dp[1][i] = 1;
}

for (let i = 2; i <= n; i++) {
  for (let j = 0; j <= 9; j++) {
    if (j === 0) dp[i][j] = dp[i - 1][j + 1];
    else if (j === 9) dp[i][j] = dp[i - 1][j - 1];
    else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
  }
}

console.log(dp[n].reduce((sum, acc) => (sum + acc) % 1000000000, 0));