const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const nums = input[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);
const arr = Array(M);
const results = [];

recursion(0, 0);

function recursion(k, start) {
  if (k === M) {
    results.push(arr.join(' '));
    return;
  }
  let prev = -1;
  for (let i = start; i < N; i++) {
    if (prev !== nums[i]) {
      arr[k] = nums[i];
      prev = nums[i];
      recursion(k + 1, i);
    }
  }
}

console.log(results.join('\n'));
