const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');
let n = Number(input[0]);

// Please Write your code here.
let answer = [];
function recursion(n) {
    if (n < 1) return;
    answer.push(n);
    recursion(n - 1);
    answer.push(n);
}

recursion(n);
console.l