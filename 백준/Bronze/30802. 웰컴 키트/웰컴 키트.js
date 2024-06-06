const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = require('fs').readFileSync(filepath).toString().trim().split('\n');
const n = +input.shift();
const participants = input[0].trim().split(' ').map(Number);
const [T, P] = input[1].split(' ').map(Number);

let tBundles = 0, pBundles, pSingle;
for(let i =0; i<6; i++){
    tBundles += Math.floor(participants[i] / T);
    if(participants[i] % T != 0)
        tBundles += 1; //나누어 떨어지지않으면 한묶음 추가
}
pBundles = Math.floor(n / P);
pSingle = n % P;
console.log(`${tBundles}\n${pBundles} ${pSingle}`)