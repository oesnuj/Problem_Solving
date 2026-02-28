const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const order = new Map();
const count = new Map();

const [N, C] = input[0].split(' ').map(Number);
const a = input[1].split(' ').map(Number);

let rank = 1;
a.forEach((e) => {
  count.set(e, (count.get(e) ?? 0) + 1);
  if (!order.get(e)) order.set(e, rank++);
});

function compare(a, b) {
  //2. 빈도가 같다면 먼저 등장한 것
  if (count.get(a) === count.get(b)) return order.get(a) - order.get(b);
  //1. 빈도가 높은 것
  return count.get(b) - count.get(a);
}

a.sort(compare);
console.log(a.join(' '));