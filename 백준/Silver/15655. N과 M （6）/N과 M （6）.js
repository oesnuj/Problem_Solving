const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const nums = input[1].split(' ').map(Number);
const arr = Array(M);

nums.sort((a, b) => a - b);
recursion(0, 0);

function recursion(k, start) {
  if (k === M) {
    console.log(arr.join(' '));
    return;
  }
  for (let i = start; i < N; i++) {
    arr[k] = nums[i];
    recursion(k + 1, i + 1);
  }
}