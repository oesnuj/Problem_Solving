const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M, R] = input[0].split(' ').map(Number);
const adjList = Array.from({ length: N + 1 }, () => []);
const visited = Array(N + 1).fill(0);
let order = 1;

for (let i = 1; i <= M; i++) {
  const [u, v] = input[i].split(' ').map(Number);
  adjList[u].push(v);
  adjList[v].push(u);
}
adjList.forEach((list) => list.sort((a, b) => a - b));

const queue = [R];
let head = 0;
visited[R] = order++;

while (head < queue.length) {
  const node = queue[head++];

  adjList[node].forEach((u) => {
    if (!visited[u]) {
      queue.push(u);
      visited[u] = order++;
    }
  });
}

console.log(visited.slice(1).join('\n'));
