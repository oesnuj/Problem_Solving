const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const flowers = [];

for (let i = 1; i <= n; i++) {
  const [sm, sd, em, ed] = input[i].split(' ').map(Number);
  flowers.push([sm * 100 + sd, em * 100 + ed]);
}

flowers.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

let i = 0;
let count = 0;
let current = 301;
let maxEnd = 0;

while (current <= 1130) {
  let found = false;

  while (i < n && flowers[i][0] <= current) {
    maxEnd = Math.max(maxEnd, flowers[i][1]);
    i++;
    found = true;
  }

  if (!found) {
    console.log(0);
    return;
  }

  current = maxEnd;
  count++;
}

console.log(count);