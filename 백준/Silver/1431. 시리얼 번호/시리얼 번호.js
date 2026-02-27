const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : 'input.txt', 'utf8')
  .trim()
  .split('\n');

const n = +input[0];
const a = [];
for (let i = 1; i <= n; i++) {
  a.push(input[i].trim());
}

a.sort((a, b) => {
  if (a.length === b.length) {
    let sumA = 0,
      sumB = 0;

    for (const c of a) {
      if (c >= '0' && c <= '9') sumA += c - '0';
    }
    for (const c of b) {
      if (c >= '0' && c <= '9') sumB += c - '0';
    }
    if (sumA === sumB) return a < b ? -1 : a > b ? 1 : 0; // 3. 사전순
    return sumA - sumB; //2. 자릿수 합 순
  }
  return a.length - b.length; // 1. 길이순
});

console.log(a.join('\n'));
