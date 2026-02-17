const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const arr = [0, ...input[1].split(' ').map(Number)];
const queries = input.slice(2).map((v) => v.split(' ').map(Number));

const dp = Array(N + 1).fill(0);
for (let i = 1; i <= N; i++) {
  dp[i] = dp[i - 1] + arr[i];
}

const answer = [];
queries.forEach(([i, j]) => {
  answer.push(dp[j] - dp[i - 1]);
});
console.log(answer.join('\n'));
