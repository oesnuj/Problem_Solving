const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');
//입력 데이터 정리
const n = +input.shift();
const files = input.map(x => x.trim().split('.').pop());

let map = new Map();

files.forEach(extension => {
    map.set(extension, (map.get(extension) || 0) + 1);
});

const sortedEntries = [...map.entries()].sort((a, b) => a[0].localeCompare(b[0]));

printResult();

function printResult() {
    let result = '';
    for (const [key, value] of sortedEntries) {
      result += `${key} ${value}\n`;
    }
    console.log(result.trim());
  }