const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

// w(a,b,c)는 순수 함수이므로 dp를 테스트 케이스 간에 재사용한다
const dp = Array.from({ length: 21 }, () => Array.from({ length: 21 }, () => Array(21).fill(null)));

input.forEach((e) => {
  const [a, b, c] = e.split(' ').map(Number);
  if (a === -1 && b === -1 && c === -1) return;
  console.log(`w(${a}, ${b}, ${c}) = ${w(a, b, c)}`);
});

function w(a, b, c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }

  if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  }

  if (dp[a][b][c] !== null) return dp[a][b][c];

  if (a < b && b < c) {
    return (dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
  }

  return (dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
}
