const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split(/\s+/);

const n = Number(input[0]);
const arr = input.slice(1, n + 1).map((e) => Number(reverse(e)));

arr.sort((a, b) => a - b);

console.log(arr.join('\n'));

function reverse(str) {
  const a = str.split('');
  const r = a.reverse();
  return r.join('');
}