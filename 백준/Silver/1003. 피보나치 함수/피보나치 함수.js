const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const data = input.slice(1);

data.forEach((e) => {
  const dp = Array(N).fill(0);

  function fibonacci(x) {
    if (dp[x]) return dp[x];
    if (x == 0) return { zero: 1, one: 0 };
    if (x == 1) return { zero: 0, one: 1 };
    const a = fibonacci(x - 2);
    const b = fibonacci(x - 1);
    dp[x] = { zero: a.zero + b.zero, one: a.one + b.one };
    return dp[x];
  }

  const { zero, one } = fibonacci(e);
  console.log(`${zero} ${one}`);
});
