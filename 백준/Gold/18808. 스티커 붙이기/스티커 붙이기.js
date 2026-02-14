const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

let line = 0;
const next = () => input[line++];

const [N, M, K] = next().split(' ').map(Number);
const laptop = Array.from({ length: N }, () => Array(M).fill(0));
const stickers = [];

for (let k = 0; k < K; k++) {
  const [R, C] = next().split(' ').map(Number);

  const sticker = [];
  for (let r = 0; r < R; r++) {
    sticker.push(next().split(' ').map(Number));
  }

  stickers.push(sticker);
}

// 스티커 붙일 수 있는지 검사
function canPaste(sticker, sr, sc) {
  const R = sticker.length;
  const C = sticker[0].length;

  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      if (sticker[r][c] === 1 && laptop[sr + r][sc + c] === 1) {
        return false;
      }
    }
  }
  return true;
}

// 실제로 붙이기
function paste(sticker, sr, sc) {
  const R = sticker.length;
  const C = sticker[0].length;

  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      if (sticker[r][c] === 1) {
        laptop[sr + r][sc + c] = 1;
      }
    }
  }
}

// 90도 시계방향 회전
function rotate(sticker) {
  const R = sticker.length;
  const C = sticker[0].length;

  const rotated = Array.from({ length: C }, () => Array(R).fill(0));

  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      rotated[c][R - 1 - r] = sticker[r][c];
    }
  }

  return rotated;
}

// 보드 전체 탐색 후 붙이기 시도
function tryPaste(sticker) {
  const R = sticker.length;
  const C = sticker[0].length;

  for (let r = 0; r <= N - R; r++) {
    for (let c = 0; c <= M - C; c++) {
      if (canPaste(sticker, r, c)) {
        paste(sticker, r, c);
        return true;
      }
    }
  }
  return false;
}

stickers.forEach((sticker) => {
  // 최대 4번 회전 시도
  for (let rot = 0; rot < 4; rot++) {
    if (tryPaste(sticker)) break;
    sticker = rotate(sticker);
  }
});

let answer = 0;

for (let r = 0; r < N; r++) {
  for (let c = 0; c < M; c++) {
    if (laptop[r][c] === 1) answer++;
  }
}

console.log(answer);
