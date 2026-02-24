const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = input[1].split(' ').map(Number);
const target = input[3].split(' ').map(Number);

a.sort((a, b) => a - b);
const answer = [];
target.forEach((t) => answer.push(binarySearch(t)));
console.log(answer.join('\n'));

function binarySearch(target) {
  let st = 0;
  let en = n - 1;
  while (st <= en) {
    const mid = (st + en) >> 1;
    if (a[mid] < target) st = mid + 1;
    else if (a[mid] > target) en = mid - 1;
    else return 1;
  }
  return 0;
}
