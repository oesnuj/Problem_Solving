const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const visited = Array.from({ length: N }, () => Array(N).fill(false));
const grid = input.slice(1).map((line) => line.split('').map(Number));
const dx = [-1, 1, 0, 0];
const dy = [0, 0, -1, 1];
const isValid = (x, y) => x >= 0 && x < N && y >= 0 && y < N;

function dfs(x, y) {
  visited[x][y] = true;
  let size = 1;

  for (let i = 0; i < 4; i++) {
    const nx = x + dx[i];
    const ny = y + dy[i];
    if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] === 1) {
      size += dfs(nx, ny);
    }
  }
  return size;
}

const areas = [];
for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (!visited[i][j] && grid[i][j] === 1) {
      areas.push(dfs(i, j));
    }
  }
}

areas.sort((a, b) => a - b);
console.log(areas.length + '\n' + areas.join('\n'));
