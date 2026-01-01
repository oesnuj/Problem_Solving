const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs
  .readFileSync(filepath)
  .toString()
  .trim()
  .split('\n')
  .map((v) => v.trim());



let idx = 1; // input[0] = t
const t = Number(input[0]);
let result = [];

for (let tc = 0; tc < t; tc++) {
  const n = Number(input[idx++]); // 이번 테스트 케이스 옷 개수

  const clothesMap = new Map();

  for (let i = 0; i < n; i++) {
    const [name, type] = input[idx++].split(' ');
    clothesMap.set(type, clothesMap.get(type) ? clothesMap.get(type) + 1 : 1);
  }

  let allCases = 1;
  clothesMap.forEach((value) => {
    allCases *= value + 1;
  });
  result.push(allCases - 1);
}
console.log(result.join('\n'));
