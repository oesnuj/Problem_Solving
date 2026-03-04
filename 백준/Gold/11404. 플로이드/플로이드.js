const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const m = +input[1];
const d = Array.from({ length: n + 1 }, (_, i) => Array.from({ length: n + 1 }, (_, j) => (i === j ? 0 : Infinity)));

for (i = 2; i < m + 2; i++) {
  const [s, e, c] = input[i].split(' ').map(Number);
  d[s][e] = Math.min(d[s][e], c);
}

for (let k = 1; k <= n; k++) {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
    }
  }
}

const answer = [];
for (let i = 1; i <= n; i++) {
  answer.push(d[i].slice(1).map(v => v === Infinity ? 0 : v).join(' '));
}
console.log(answer.join('\n'));