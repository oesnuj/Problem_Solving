const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const initialBoard = [];

const dirs = [0, 1, 2, 3];

for (let i = 1; i <= N; i++) {
  initialBoard.push(input[i].split(' ').map(Number));
}

let result = 0;
let board = [];
const MOVE = 5;
//5방향을 선택하는 모든 경우의 수 (조합)
for (let i = 0; i < 1 << (2 * MOVE); i++) {
  board = initialBoard.map((row) => [...row]);
  let brute = i;
  //5방향
  for (let j = 0; j < MOVE; j++) {
    let dir = brute % 4;
    brute = Math.trunc(brute / 4);
    tilt(dir);
  }

  for (let r = 0; r < N; r++) {
    for (let c = 0; c < N; c++) {
      result = Math.max(result, board[r][c]);
    }
  }
}
console.log(result);

function rotate() {
  const rotated = Array.from({ length: N }, () => Array(N).fill(0));

  for (let r = 0; r < N; r++) {
    for (let c = 0; c < N; c++) {
      rotated[c][N - 1 - r] = board[r][c];
    }
  }

  return rotated;
}

function tilt(dir) {
  let rot = dirs[dir];

  for (let i = 0; i < rot; i++) {
    board = rotate(board);
  }

  tiltUp();

  for (let i = 0; i < (4 - rot) % 4; i++) {
    board = rotate(board);
  }
}

function tiltUp() {
  for (let c = 0; c < N; c++) {
    let nums = [];

    //1. 현재 column에서 0을 제외한 타일을 위쪽 기준으로 모음 (compress)
    for (let r = 0; r < N; r++) {
      if (board[r][c] !== 0) {
        nums.push(board[r][c]);
      }
    }

    //2. 인접한 동일 숫자를 한 번만 합치고 다음 칸은 건너뜀 (merge)
    for (let i = 0; i < nums.length; i++) {
      if (nums[i] === nums[i + 1]) {
        nums[i] += nums[i + 1];
        nums[i + 1] = 0;
        i += 1;
      }
    }

    // 3. merge로 생긴 0을 제거해 다시 한쪽으로 압축 (re-compress)
    nums = nums.filter((v) => v !== 0);

    // 4. 계산된 결과를 위쪽부터 채우고 남은 칸은 0으로 채움
    for (let r = 0; r < N; r++) {
      board[r][c] = nums[r] ?? 0;
    }
  }
}
