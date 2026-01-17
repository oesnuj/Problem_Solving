const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

let T = +input[0];
let idx = 1;

const dx = [-1, 1, 0, 0];
const dy = [0, 0, -1, 1];

while (T--) {
  const [M, N, K] = input[idx++].split(' ').map(Number);
  const grid = Array.from({ length: M }, () => Array(N).fill(0));
  const isValid = (x, y) => x >= 0 && x < M && y >= 0 && y < N;

  for (let i = 0; i < K; i++) {
    const [x, y] = input[idx++].split(' ').map(Number);
    grid[x][y] = 1;
  }

  function dfs(x, y) {
    grid[x][y] = 0;

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (isValid(nx, ny) && grid[nx][ny] === 1) {
        dfs(nx, ny);
      }
    }
  }

  let result = 0;
  for (let i = 0; i < M; i++) {
    for (let j = 0; j < N; j++) {
      if (grid[i][j] === 1) {
        dfs(i, j);
        result++;
      }
    }
  }
  console.log(result);
}
