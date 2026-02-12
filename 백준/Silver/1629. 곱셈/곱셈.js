const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [a, b, c] = input[0].split(' ').map(BigInt);

function recursion(a, b, c) {
  a = a % c;
  if (b === 0n) return 1n;
  if (b === 1n) return a % c;
  let val = recursion(a, b / 2n, c);
  val = (val * val) % c;

  if (b % 2n === 0n) return val;
  return (val * a) % c;
}

console.log(String(recursion(a, b, c)));