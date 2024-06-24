const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const n= +input[0];
const str= input[1];

let result = "";
		
for (let i = 0; i < n; i++) { 
	if (str[i] === str[i].toUpperCase()) { 
		result += str[i].toLowerCase();
	} else { 
		result += str[i].toUpperCase();
	}
}
console.log(result);