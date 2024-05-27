const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');
const n = input[0];
const arr= input.slice(1).map(line => line.split(' ').map(Number));
for (let i = 0; i < arr.length; i++) {
    arr[i][0] -= 1;
}

const cowArr = new Array(10).fill(-1);
let count = 0;
for(let i = 0; i < n; i++)
{
    if(cowArr[arr[i][0]] == -1){
        cowArr[arr[i][0]] = arr[i][1];
    }
    else if(cowArr[arr[i][0]] != arr[i][1]){
        cowArr[arr[i][0]] = arr[i][1];
        count++;
    }
} 
console.log(count);