const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const T = +input[0];
const answer = [];
let index = 1;
for (let t = 0; t < T; t++) {
  const [N, M] = input[index++].split(' ').map(Number);
  const A = input[index++].split(' ').map(Number);
  const B = input[index++].split(' ').map(Number);

  A.sort((a, b) => a - b);
  B.sort((a, b) => a - b);

  let cnt = 0;
  for (let i = A.length - 1; i >= 0; i--) {
    cnt += lower_idx(A[i], B);
  }
  answer.push(cnt);
}
console.log(answer.join('\n'));

function lower_idx(target, a) {
  let st = 0;
  let en = a.length;
  while (st < en) {
    const mid = (st + en) >> 1;
    if (a[mid] >= target)
      en = mid;
    else st = mid + 1;
  }
  return st;
}