const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const info = input
  .slice(1)
  .map((line) => line.split(' ').map(Number))
  .sort((a, b) => a[1] - b[1] || a[0] - b[0]);

let count = 0;
let endTime = 0;

for (const [start, end] of info) {
  if (start >= endTime) {
    count++;
    endTime = end;
  }
}

console.log(count);
