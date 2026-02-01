const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const zero = input[0].split('1').filter((e) => e !== '').length;
const one = input[0].split('0').filter((e) => e !== '').length;
console.log(Math.min(zero, one));