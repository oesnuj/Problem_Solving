const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const s = input[0];
const list = [];
for (let i = 0; i < s.length; i++) {
  list.push(s.slice(i));
}
list.sort();
console.log(list.join('\n'));
