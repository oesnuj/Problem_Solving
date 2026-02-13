const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const N = +input[0];
const sliced_input = input.slice(1);
const eggs = sliced_input.map((e) => e.trim().split(' ').map(Number));

let max = 0;
recursion(0);
console.log(max);

function recursion(k) {
  if (k === N) {
    const broken = eggs.filter((e) => e[0] <= 0).length;
    max = Math.max(max, broken);
    return;
  }

  if (eggs[k][0] <= 0) {
    recursion(k + 1);
    return;
  }

  let targets = [];
  for (let i = 0; i < N; i++) {
    if (i !== k && eggs[i][0] > 0) targets.push(i);
  }

  if (targets.length === 0) {
    recursion(k + 1);
    return;
  }

  for (const i of targets) {
    eggs[k][0] -= eggs[i][1];
    eggs[i][0] -= eggs[k][1];

    recursion(k + 1);

    eggs[k][0] += eggs[i][1];
    eggs[i][0] += eggs[k][1];
  }
}
