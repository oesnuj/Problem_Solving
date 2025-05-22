const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [N, M] = input[0].trim().split(' ').map(Number);

const map = new Map();
for (let i = 1; i <= N; i++) {
  const [key, value] = input[i].split(' ');
  map.set(key, value);
}

for (let i = N + 1; i < N + 1 + M; i++) {
  console.log(map.get(input[i].trim()));
}