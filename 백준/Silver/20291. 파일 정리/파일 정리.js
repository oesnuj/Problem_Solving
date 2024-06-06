const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');
const n = +input.shift();
const files = input.map(x => {
    const parts = x.trim().split('.');
    const name = parts.slice(0, -1).join('.');
    const extension = parts[parts.length - 1];
    return { name, extension };
});

let map =new Map();

for(let i = 0; i < n; i++){
        if(map.has(files[i].extension))
            map.set(files[i].extension, map.get(files[i].extension) + 1);
        else
            map.set(files[i].extension, 1)
    }
const mapToArray = [...map];
mapToArray.sort();

printResult();

function printResult() {
    let result = '';
    for (const [key, value] of mapToArray) {
      result += `${key} ${value}\n`;
    }
    console.log(result.trim());
  }