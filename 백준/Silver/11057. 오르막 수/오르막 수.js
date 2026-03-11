const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const MOD = 10007;

// dp[i][0 ~ 9]: i자리수이면서 0~9로 끝나는 오르막 수 개수
// dp[i][9] = dp[i-1][0] 부터 dp[i-1][9]까지의 합
const dp = Array.from({ length: n + 1 }, () => Array(10).fill(1));

for (let i = 2; i <= n; i++) {
  for (let j = 1; j < 10; j++) {
    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
  }
}

const answer = dp[n].reduce((acc, cur) => (acc + cur) % MOD, 0);
console.log(answer);