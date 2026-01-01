const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().split('\n');

const n = +input[0];
console.log(n % 2 ? 'SK' : 'CY');
