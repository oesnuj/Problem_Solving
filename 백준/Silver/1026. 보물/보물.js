const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [n, arr1, arr2] = input;

a = arr1.split(' ').map(Number);
b = arr2.split(' ').map(Number);

a.sort((a, b) => a - b);
b.sort((a, b) => b - a);

let answer = 0;
for (let i = 0; i < n; i++) {
  answer += a[i] * b[i];
}
console.log(answer);