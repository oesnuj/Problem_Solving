const { count } = require('console');

const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const board = input.slice(1).map((e) => e.trim().split(' ').map(Number));
const board2 = Array.from({ length: N }, () => Array(M));
const cctvs = [];
const dr = [1, 0, -1, 0];
const dc = [0, 1, 0, -1];
let result = Infinity;

for (let r = 0; r < N; r++) {
  for (let c = 0; c < M; c++) {
    const type = board[r][c];
    if (type >= 1 && type <= 5) {
      cctvs.push([r, c, type]);
    }
  }
}

for (let i = 0; i < 1 << (2 * cctvs.length); i++) {
  let brute = i;
  for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
      board2[r][c] = board[r][c];
    }
  }
  for (let j = 0; j < cctvs.length; j++) {
    let dir = brute % 4;
    brute = Math.trunc(brute / 4);
    const [r, c, type] = cctvs[j];
    if (type === 1) {
      watch(r, c, dir);
    } else if (type === 2) {
      watch(r, c, dir);
      watch(r, c, dir + 2);
    } else if (type === 3) {
      watch(r, c, dir);
      watch(r, c, dir + 1);
    } else if (type === 4) {
      watch(r, c, dir);
      watch(r, c, dir + 1);
      watch(r, c, dir + 2);
    } else {
      watch(r, c, dir);
      watch(r, c, dir + 1);
      watch(r, c, dir + 2);
      watch(r, c, dir + 3);
    }
  }

  let cnt = 0;
  for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
      cnt += board2[r][c] === 0;
    }
  }

  result = Math.min(result, cnt);
}

console.log(result);

function isBlock(a, b) {
  return a < 0 || a >= N || b < 0 || b >= M;
}

function watch(r, c, dir) {
  dir %= 4;
  while (true) {
    r += dr[dir];
    c += dc[dir];
    if (isBlock(r, c) || board2[r][c] === 6) return;
    if (board2[r][c] > 0) continue;
    board2[r][c] = -1;
  }
}