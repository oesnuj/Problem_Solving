const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const board = input.map((e) => e.trim().split(''));
let cnt = 0;
const selected = Array(7);
const dirs = [
  [1, 0],
  [0, 1],
  [-1, 0],
  [0, -1],
];

combination(0, 0);
console.log(cnt);

function combination(k, start) {
  if (k === 7) {
    if (!isConnected()) return;

    let sCnt = 0;
    for (let i = 0; i < 7; i++) {
      const x = Math.floor(selected[i] / 5);
      const y = selected[i] % 5;
      if (board[x][y] === 'S') sCnt++;
    }
    if (sCnt >= 4) cnt++;
    return;
  }

  for (let i = start; i < 25; i++) {
    selected[k] = i;
    combination(k + 1, i + 1);
  }
}

function isConnected() {
  const isSelected = Array(25).fill(false);
  for (let i = 0; i < 7; i++) {
    isSelected[selected[i]] = true;
  }

  const isVisited = Array(25).fill(false);
  const queue = [selected[0]];
  isVisited[selected[0]] = true;
  let head = 0;
  let count = 1;

  while (head < queue.length) {
    const cur = queue[head++];
    const x = Math.floor(cur / 5);
    const y = cur % 5;

    for (const [dx, dy] of dirs) {
      const nx = x + dx;
      const ny = y + dy;
      if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
      const next = nx * 5 + ny;
      if (isSelected[next] && !isVisited[next]) {
        isVisited[next] = true;
        queue.push(next);
        count++;
      }
    }
  }

  return count === 7;
}
