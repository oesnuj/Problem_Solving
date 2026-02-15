const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const result = [];

const dp = Array(11);
dp[1] = 1;
dp[2] = 2;
dp[3] = 4;
for (let j = 4; j <= 11; j++) {
  dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
}

for (let i = 1; i <= N; i++) {
  const num = +input[i];
  result.push(dp[num]);
}

console.log(result.join('\n'));
