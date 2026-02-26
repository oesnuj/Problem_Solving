const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);

const set = new Set();
for (let i = 1; i <= N; i++) {
  set.add(input[i]);
}

let count = 0;

for (let i = N + 1; i <= N + M; i++) {
  if (set.has(input[i])) count++;
}

console.log(count);