const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
console.log(`a = ${input[0]}\nb = ${input[1]}`)