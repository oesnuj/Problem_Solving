const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];

const triangle = [0];
for (let i = 1; i <= N; i++) {
  triangle.push([0, ...input[i].trim().split(' ').map(Number)]);
}

const dp = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));

dp[1][1] = triangle[1][1];

for (let i = 2; i <= N; i++) {
  for (let j = 1; j <= i; j++) {
    dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
  }
}

console.log(Math.max(...dp[N]));
