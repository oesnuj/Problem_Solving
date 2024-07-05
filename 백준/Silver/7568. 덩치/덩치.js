const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const datas = input.map(el => el.split(' ').map(Number))

let result = "";
datas.forEach((target) => {
    let cnt = 1;
    datas.forEach((data) => {
        if(target[0] < data[0] && target[1] < data[1]) {
            cnt++;
        }
    })
    result += `${cnt} `;
})
console.log(result);