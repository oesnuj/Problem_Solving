const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = input.slice(1).map(Number);
a.sort((a, b) => a - b);

const two = [];
for (let i = 0; i < n; i++) {
  for (let j = i; j < n; j++) {
    two.push(a[i] + a[j]);
  }
}
two.sort((a, b) => a - b);

let answer = 0;
for (let i = n - 1; 0 < i; i--) {
  for (let j = 0; j < i; j++) {
    if (binarySearch(a[i] - a[j])) {
      console.log(a[i]);
      return;
    }
  }
}
console.log(answer);

function binarySearch(target) {
  let st = 0;
  let en = two.length - 1;
  while (st <= en) {
    const mid = (st + en) >> 1;
    if (target < two[mid]) en = mid - 1;
    else if (target > two[mid]) st = mid + 1;
    else return 1;
  }
  return 0;
}