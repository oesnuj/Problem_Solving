const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, K] = input[0].split(' ').map(Number);

const MAX = 100000;
const dist = Array(MAX + 1).fill(-1);
const ways = Array(MAX + 1).fill(0);

const queue = [N];
let head = 0;

dist[N] = 0;
ways[N] = 1;

while (head < queue.length) {
  const x = queue[head++];

  for (const nx of [x - 1, x + 1, x * 2]) {
    if (nx < 0 || nx > MAX) continue;

    // 처음 방문하는 경우
    if (dist[nx] === -1) {
      dist[nx] = dist[x] + 1;
      ways[nx] = ways[x];
      queue.push(nx);
    }
    // 같은 최단 거리로 또 도달한 경우
    else if (dist[nx] === dist[x] + 1) {
      ways[nx] += ways[x];
    }
  }
}

console.log(dist[K] + '\n' + ways[K]);