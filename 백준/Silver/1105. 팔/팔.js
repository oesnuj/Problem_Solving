const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split(' ');
const [L, R]= input;

console.log(calc());

function calc(){
    let cnt = 0;
    if(L.length !== R.length) return cnt;
    for(let i = 0; i < L.length; i++){
        if(L[i]=== '8' && R[i] === '8' ) cnt++;
        else if(L[i] !== R[i]) break;
    }
    return cnt;
}