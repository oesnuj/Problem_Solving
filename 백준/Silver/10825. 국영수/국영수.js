const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];

const list = input.slice(1).map((v) => {
  const [name, k, e, m] = v.split(' ');
  return [name, +k, +e, +m];
});

list.sort((a, b) => {
  if (a[1] !== b[1]) return b[1] - a[1]; // 국어 내림차순
  if (a[2] !== b[2]) return a[2] - b[2]; // 영어 오름차순
  if (a[3] !== b[3]) return b[3] - a[3]; // 수학 내림차순
  return a[0] < b[0] ? -1 : 1; // 이름 사전순
});

console.log(list.map((v) => v[0]).join('\n'));