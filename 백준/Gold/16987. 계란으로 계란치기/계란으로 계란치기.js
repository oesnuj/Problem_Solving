const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const eggs = input.slice(1).map((e) => e.split(' ').map(Number));

let max = 0;
let brokenCnt = 0;
recursion(0);
console.log(max);

function recursion(k) {
  // 모든 턴 종료
  if (k === N) {
    max = Math.max(max, brokenCnt);
    return;
  }

  // 현재 계란이 깨졌거나 더 이상 충돌 불가능
  if (eggs[k][0] <= 0 || brokenCnt === N - 1) {
    recursion(k + 1);
    return;
  }

  for (let i = 0; i < N; i++) {
    if (i === k || eggs[i][0] <= 0) continue;

    // 충돌
    eggs[k][0] -= eggs[i][1];
    eggs[i][0] -= eggs[k][1];
    let add = 0;
    if (eggs[k][0] <= 0) add++;
    if (eggs[i][0] <= 0) add++;
    brokenCnt += add;

    recursion(k + 1);

    // 복구
    brokenCnt -= add;
    eggs[k][0] += eggs[i][1];
    eggs[i][0] += eggs[k][1];
  }
}
