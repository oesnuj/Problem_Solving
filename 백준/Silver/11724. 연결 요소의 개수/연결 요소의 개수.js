const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const adjList = Array.from({ length: N + 1 }, () => []);
const visited = Array(N).fill(0);

input.slice(1).forEach((e) => {
  const [u, v] = e.split(' ').map(Number);
  adjList[u].push(v);
  adjList[v].push(u);
});

let cnt = 0;
for (let i = 1; i <= N; i++) {
  if (!visited[i]) {
    bfs(i);
    cnt++;
  }
}
console.log(cnt);

function bfs(i) {
  const queue = [i];
  let head = 0;
  while (head < queue.length) {
    const node = queue[head++];
    for (const u of adjList[node]) {
      if (visited[u]) continue;
      queue.push(u);
      visited[u] = true;
    }
  }
}