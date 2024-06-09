const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = require('fs').readFileSync(filepath).toString().trim();

let arr = new Array(26).fill(0);
for(let i = 0; i< input.length; i++){
    arr[input.charCodeAt(i) - 'a'.charCodeAt(0)]++;
}

console.log(arr.join(" "));