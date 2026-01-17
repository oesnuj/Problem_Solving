const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');
const [N, M, V] = input[0].split(' ').map(Number);

const adjList = Array.from({ length: N + 1 }, () => []);
const visitedByDFS = Array(N + 1).fill(false);
const visitedByBFS = Array(N + 1).fill(false);
const dfsResult = [];
const bfsResult = [];

for (let i = 1; i <= M; i++) {
  const [u, v] = input[i].split(' ').map(Number);
  adjList[u].push(v);
  adjList[v].push(u);
}

for (let i = 1; i <= N; i++) {
  adjList[i].sort((a, b) => a - b);
}

DFS(V);
BFS(V);
console.log(dfsResult.join(' '));
console.log(bfsResult.join(' '));

function DFS(node) {
  visitedByDFS[node] = true;
  dfsResult.push(node);

  for (const n of adjList[node]) {
    if (!visitedByDFS[n]) {
      DFS(n);
    }
  }
}

function BFS(start) {
  const queue = [start];
  visitedByBFS[start] = true;
  bfsResult.push(start);
  let head = 0;

  while (head < queue.length) {
    const node = queue[head++];

    for (const n of adjList[node]) {
      if (!visitedByBFS[n]) {
        visitedByBFS[n] = true;
        bfsResult.push(n);
        queue.push(n);
      }
    }
  }
}
