const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = input[1].split(' ').map(Number);

const sorted = [...a].sort((a, b) => a - b);
const uni = [];
for (let i = 0; i < n; i++) {
  if (i === 0 || sorted[i] !== sorted[i - 1]) {
    uni.push(sorted[i]);
  }
}

const answer = [];
a.forEach((e) => answer.push(lower_bound(e)));
console.log(answer.join(' '));

function lower_bound(target) {
  let st = 0;
  let en = uni.length;
  while (st < en) {
    const mid = (st + en) >> 1;
    if (uni[mid] >= target) en = mid;
    else st = mid + 1;
  }
  return st;
}