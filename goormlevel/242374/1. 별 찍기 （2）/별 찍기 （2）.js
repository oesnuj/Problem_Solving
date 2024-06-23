const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = require('fs').readFileSync(filepath).map(Number);


let star = "";
for (let i = 0; i < input; i++) {
	star += "*";
}

for (let i = 0; i < input; i++) {
	console.log(star);
	star = star.substring(0, input - i - 1);
}
