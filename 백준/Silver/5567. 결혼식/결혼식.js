const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const m = +input[1];

const adjList = Array.from({ length: n + 1 }, () => []);
const visited = Array(n + 1).fill(-1);

for (let i = 2; i < m + 2; i++) {
  const [a, b] = input[i].split(' ').map(Number);
  adjList[a].push(b);
  adjList[b].push(a);
}

const queue = [1];
visited[1] = 0;
let head = 0;

while (head < queue.length) {
  const f = queue[head++];
  if (visited[f] === 2) continue;

  for (const a of adjList[f]) {
    if (visited[a] < 0) {
      visited[a] = visited[f] + 1;
      queue.push(a);
    }
  }
}

console.log(visited.filter((v) => v > 0 && v <= 2).length);