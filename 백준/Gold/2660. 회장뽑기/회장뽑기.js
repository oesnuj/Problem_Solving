const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const adjList = Array.from({ length: n + 1 }, () => []);
const score = Array.from({ length: n + 1 });

let i = 1;
while (1) {
  const [u, v] = input[i++].split(' ').map(Number);
  if (u === -1 && v === -1) break;
  adjList[u].push(v);
  adjList[v].push(u);
}

for (let i = 1; i <= n; i++) {
  score[i] = bfs(i);
}

const minScore = Math.min(...score.slice(1));
const candidates = [];

for (let i = 1; i <= n; i++) {
  if (score[i] === minScore) {
    candidates.push(i);
  }
}

console.log(minScore, candidates.length);
console.log(candidates.join(' '));

function bfs(start) {
  const visited = Array(n + 1).fill(-1);
  const queue = [start];
  visited[start] = 0;

  for (let head = 0; head < queue.length; head++) {
    const cur = queue[head];

    for (const next of adjList[cur]) {
      if (visited[next] === -1) {
        visited[next] = visited[cur] + 1;
        queue.push(next);
      }
    }
  }

  return Math.max(...visited);
}