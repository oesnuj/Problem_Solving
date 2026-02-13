const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const nums = input[1].split(' ').map(Number);
const arr = Array(M);
const results = [];
nums.sort((a, b) => a - b);
recursion(0);

function recursion(k) {
  if (k === M) {
    results.push(arr.join(' '));
    return;
  }
  for (let i = 0; i < N; i++) {
    arr[k] = nums[i];
    recursion(k + 1);
  }
}

console.log(results.join('\n'));
