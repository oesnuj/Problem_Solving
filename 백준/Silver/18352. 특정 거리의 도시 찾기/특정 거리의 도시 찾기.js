const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M, K, X] = input[0].split(' ').map(Number);
const adjList = Array.from({ length: N + 1 }, () => []);
const distance = Array(N + 1).fill(-1);

for (let i = 1; i <= M; i++) {
  const [A, B] = input[i].split(' ').map(Number);
  adjList[A].push(B);
}

const queue = [X];
distance[X] = 0;
let head = 0;

while (head < queue.length) {
  const node = queue[head++];
  if (distance[node] >= K) break;

  for (const n of adjList[node]) {
    if (distance[n] === -1) {
      distance[n] = distance[node] + 1;
      queue.push(n);
    }
  }
}

const result = [];
for (let i = 1; i <= N; i++) {
  if (distance[i] === K) {
    result.push(i);
  }
}

console.log(result.length ? result.join('\n') : -1);
