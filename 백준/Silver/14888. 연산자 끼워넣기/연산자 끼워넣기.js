const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const nums = input[1].split(' ').map(Number);
const [plus, minus, mul, div] = input[2].split(' ').map(Number);
const result = { max: -Infinity, min: Infinity };

dfs(1, nums[0], plus, minus, mul, div);

function dfs(index, current, plus, minus, mul, div) {
  if (index >= nums.length) {
    result.max = Math.max(result.max, current);
    result.min = Math.min(result.min, current);
    return;
  }

  if (plus) dfs(index + 1, current + nums[index], plus - 1, minus, mul, div);
  if (minus) dfs(index + 1, current - nums[index], plus, minus - 1, mul, div);
  if (mul) dfs(index + 1, current * nums[index], plus, minus, mul - 1, div);
  if (div) dfs(index + 1, Math.trunc(current / nums[index]), plus, minus, mul, div - 1);
}

console.log(result.max + '\n' + result.min);
