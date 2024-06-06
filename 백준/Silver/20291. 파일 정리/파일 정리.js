const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');
//입력 데이터 정리
const n = +input.shift();

let myMap = new Map();

for (let i = 0; i < n; i++) {
    let x = input[i].split('.')[1];
    myMap.set(x, myMap.has(x) ? myMap.get(x) + 1 : 1);
  }

console.log(
  [...myMap]
    .map((e) => e.join(" "))
    .sort()
    .join("\n")
    .trim()
);