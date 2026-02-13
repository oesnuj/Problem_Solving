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
const isUsed = Array(N + 1).fill(false);
const results = [];

recursion(0);

function recursion(k) {
  if (k === M) {
    results.push(arr.join(' '));
    return;
  }
  let prev = -1;
  for (let i = 0; i < N; i++) {
    if (prev !== nums[i]) {
      arr[k] = nums[i];
      prev = nums[i];
      recursion(k + 1);
    }
  }
}

console.log(results.join('\n'));
