const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const costs = input.map((line) => line.split(' ').map(Number));

const [RED, GREEN, BLUE] = [0, 1, 2];
const dp = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));

for (let i = 1; i <= N; i++) {
  dp[i][RED] = Math.min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + costs[i][RED];
  dp[i][GREEN] = Math.min(dp[i - 1][RED], dp[i - 1][BLUE]) + costs[i][GREEN];
  dp[i][BLUE] = Math.min(dp[i - 1][RED], dp[i - 1][GREEN]) + costs[i][BLUE];
}

console.log(Math.min(dp[N][RED], dp[N][GREEN], dp[N][BLUE]));