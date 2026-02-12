const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];

let triangle = ['  *  ', ' * * ', '*****'];

for (let h = 3; h < N; h *= 2) {
  const pad = ' '.repeat(h);
  const top = triangle.map((s) => pad + s + pad);
  const bottom = triangle.map((s) => s + ' ' + s);
  triangle = top.concat(bottom);
}

console.log(triangle.join('\n'));