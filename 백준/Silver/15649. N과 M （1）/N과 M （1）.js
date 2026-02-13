const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);

const arr = Array(M);
const isUsed = Array(N + 1).fill(false);

recursion(0);

function recursion(k) {
  if (k === M) {
    console.log(arr.join(' '));
    return;
  }

  for (let i = 1; i <= N; i++) {
    if (!isUsed[i]) {
      arr[k] = i;
      isUsed[i] = true;
      recursion(k + 1);
      isUsed[i] = false;
    }
  }
}
