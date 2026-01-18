const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const arrSize = 100001;
const [N, K] = input[0].split(' ').map(Number);
const visited = Array(arrSize).fill(false);

const queue = [N];
visited[N] = true;
let head = 0;
let time = 0;

while (head < queue.length) {
  let size = queue.length - head;
  for (let i = 0; i < size; i++) {
    const pos = queue[head++];

    if (pos === K) {
      console.log(time);
      return;
    }

    const next = [pos + 1, pos - 1, pos * 2];
    for (const np of next) {
      if (0 <= np && np <= 100000 && !visited[np]) {
        queue.push(np);
        visited[np] = true;
      }
    }
  }
  time++;
}