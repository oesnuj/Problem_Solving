const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = input[1].split(' ').map(Number);
const m = +input[2];
const t = input[3].split(' ').map(Number);
const answer = [];

a.sort((a, b) => a - b);

t.forEach((e) => {
  answer.push(upper_index(e) - lower_index(e));
});

console.log(answer.join(' '));

function lower_index(target) {
  let st = 0;
  let en = n;
  while (st < en) {
    const mid = (st + en) >> 1;
    if (a[mid] >= target) en = mid;
    else st = mid + 1;
  }
  return st;
}

function upper_index(target) {
  let st = 0;
  let en = n;
  while (st < en) {
    const mid = (st + en) >> 1;
    if (a[mid] > target) en = mid;
    else st = mid + 1;
  }
  return st;
}