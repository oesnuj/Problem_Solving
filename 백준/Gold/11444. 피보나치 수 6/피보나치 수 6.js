const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = BigInt(input[0]);
const MOD = 1000000007n;

function fib(k) {
  if (k === 0n) return [0n, 1n];

  const [a, b] = fib(k / 2n);

  const c = (a * ((2n * b - a + MOD) % MOD)) % MOD;
  const d = (a * a + b * b) % MOD;

  if (k % 2n === 0n) {
    return [c, d];
  } else {
    return [d, (c + d) % MOD];
  }
}

console.log(fib(n)[0].toString());