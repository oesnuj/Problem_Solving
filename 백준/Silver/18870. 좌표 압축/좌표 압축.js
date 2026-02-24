const fs = require('fs');

const input = fs.readFileSync(0, 'utf8').trim().split('\n');
const n = +input[0];
const arr = input[1].split(' ').map(Number);

// 1. 중복 제거 + 정렬
const sorted = [...new Set(arr)].sort((a, b) => a - b);

// 2. 값 -> 인덱스 매핑
const indexMap = new Map();
sorted.forEach((value, index) => {
  indexMap.set(value, index);
});

// 3. 원래 배열을 압축값으로 변환
const result = arr.map(value => indexMap.get(value));

console.log(result.join(' '));