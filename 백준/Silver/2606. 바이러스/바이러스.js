const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const M = +input[1];
const adjList = Array.from({ length: N + 1 }, () => []);
const visited = Array(N + 1).fill(false);

for (let i = 0; i < M; i++) {
  const [u, v] = input[i + 2].split(' ').map(Number);
  adjList[u].push(v);
  adjList[v].push(u);
}

const queue = [1];
let head = 0;
visited[1] = true;

while (head < queue.length) {
  const node = queue[head++];
  for (const n of adjList[node]) {
    if (!visited[n]) {
      visited[n] = true;
      queue.push(n);
    }
  }
}

console.log(visited.filter((e) => e).length - 1);
