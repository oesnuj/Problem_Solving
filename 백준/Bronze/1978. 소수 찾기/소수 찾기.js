const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const a = input[1].split(' ').map(Number);
console.log(a.filter(e => isPrime(e)).length);

function isPrime(n) {
  if (n == 1) return 0;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return 0;
  }
  return 1;
}