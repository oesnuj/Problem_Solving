const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const dp = Array(N + 1).fill(0);

let count1 = 0;
let count2 = 0;

fibonacci1(N);
fibonacci2(N);

console.log(`${count1} ${count2}`);

function fibonacci1(x) {
  if (x === 1 || x === 2) {
    count1++;
    return 1;
  }
  return fibonacci1(x - 2) + fibonacci1(x - 1);
}

function fibonacci2(n) {
  dp[1] = dp[2] = 1;
  for (let i = 3; i <= n; i++) {
    count2++;
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}