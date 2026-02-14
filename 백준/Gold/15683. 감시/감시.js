const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const board = input.slice(1).map((e) => e.trim().split(' ').map(Number));
const cctvs = [];
const dr = [-1, 0, 1, 0];
const dc = [0, 1, 0, -1];
const DIRS = [
  null,
  [[0], [1], [2], [3]],
  [
    [0, 2],
    [1, 3],
  ],
  [
    [0, 1],
    [1, 2],
    [2, 3],
    [3, 0],
  ],
  [
    [0, 1, 2],
    [1, 2, 3],
    [2, 3, 0],
    [3, 0, 1],
  ],
  [[0, 1, 2, 3]],
];
let result = N * M;

for (let r = 0; r < N; r++) {
  for (let c = 0; c < M; c++) {
    const v = board[r][c];
    if (v >= 1 && v <= 5) {
      cctvs.push([r, c, v]);
    }
  }
}

recursion(0);
console.log(result);

function recursion(k) {
  // 마지막 칸 도달시 종료
  // 현재의 사각지대 계산 및 최소값 갱신
  if (k === cctvs.length) {
    result = Math.min(result, countBlindSpots());
    return;
  }

  // 현재 칸이 감시 카메라일때
  const [r, c, type] = cctvs[k];

  // 각 번호에 맞게 백트래킹
  for (const dirs of DIRS[type]) {
    const changedAll = [];

    for (const dir of dirs) {
      const changed = watch(r, c, dir);
      changedAll.push(...changed);
    }

    recursion(k + 1);

    // 복구
    for (const [rr, cc] of changedAll) {
      board[rr][cc] = 0;
    }
  }
}

function countBlindSpots() {
  let cnt = 0;

  for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
      if (board[r][c] === 0) cnt++;
    }
  }

  return cnt;
}

function watch(r, c, dir) {
  const changed = [];

  let nr = r + dr[dir];
  let nc = c + dc[dir];

  while (nr >= 0 && nr < board.length && nc >= 0 && nc < board[0].length) {
    if (board[nr][nc] === 6) break;

    if (board[nr][nc] === 0) {
      board[nr][nc] = -1;
      changed.push([nr, nc]);
    }

    nr += dr[dir];
    nc += dc[dir];
  }

  return changed;
}
