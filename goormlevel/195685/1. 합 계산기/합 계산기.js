const input = require('fs').readFileSync("/dev/stdin").toString().trim().split('\n');

const n = +input.shift();
const datas = input.map(el => el.split(' '));

console.log(calc(datas));

function calc(datas){
	let result = 0
	for(let i = 0; i < datas.length; i++){
		let A = +datas[i][0]
		let B = +datas[i][2]
		if(datas[i][1] === '+') result += A+B;
		else if(datas[i][1] === '-') result += A-B;
		else if(datas[i][1] === '*') result += A*B;
		else if(datas[i][1] === '/') result += Math.floor(A/B);
	}
	return result;
}