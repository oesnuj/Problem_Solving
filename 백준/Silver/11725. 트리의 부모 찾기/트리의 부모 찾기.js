const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];

const adjList = Array.from({ length: n + 1 }, () => []);

for (let i = 1; i < n; i++) {
  const [a, b] = input[i].split(' ').map(Number);
  adjList[a].push(b);
  adjList[b].push(a);
}

const queue = [1];
let head = 0;
const p = Array(n + 1).fill(0);
p[1] = -1;

while (head < queue.length) {
  const cur = queue[head++];
  for (const nxt of adjList[cur]) {
    if (p[cur] === nxt) continue;
    p[nxt] = cur;
    queue.push(nxt);
  }
}

console.log(p.slice(2).join('\n'));