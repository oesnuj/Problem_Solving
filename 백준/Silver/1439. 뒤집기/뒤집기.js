const s = require('fs').readFileSync(0, 'utf8').trim();

let zero = 0;
let one = 0;

// 첫 덩어리 처리
if (s[0] === '0') zero++;
else one++;

// 전환 지점 처리
for (let i = 1; i < s.length; i++) {
  if (s[i] !== s[i - 1]) {
    if (s[i] === '0') zero++;
    else one++;
  }
}

console.log(Math.min(zero, one));