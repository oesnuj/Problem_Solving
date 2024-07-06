const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const N = +input.shift();
const alphabet = input[0].split(' ')
const target = input[1]

let m = new Map()

alphabet.forEach(e => setMap(e))

result = m.get(target)
if(result === undefined) console.log(0)
else console.log(result)

function setMap(e){
	if(m.has(e)) m.set(e, m.get(e)+1);
	else m.set(e, 1);
}
