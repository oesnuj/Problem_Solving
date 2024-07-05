//const fs = require('fs');
//const input = fs.readFileSync("/dev/stdin").toString().trim();
//const n = Number(input);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n;
rl.on("line", (line) => {
    n = +line;
    main();
    rl.close();
});

rl.on("close", () => {
    process.exit();
});

function factorial(num) {
    let result = BigInt(1);
    for (let i = 2; i <= num; i++) {
        result *= BigInt(i);
    }
    return result;
}

function makeOneDigit(num){
    num = num.toString();
		let sum = BigInt(0);
		for(let i = 0; i<num.length; i++){
				sum += BigInt(num[i]);
			}
   	return sum;
}

function main(){
    let A = BigInt(factorial(n));
    while(A > 10){
        let B = BigInt(makeOneDigit(A));
        A = B;
    }
    console.log(A.toString());
    return;

}
