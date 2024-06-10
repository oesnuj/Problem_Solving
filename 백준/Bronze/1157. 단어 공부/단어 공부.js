const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let arr = new Array(26).fill(0);
rl.on('line', function (line) {
line = line.toUpperCase();
for(let i = 0; i < line.length; i++){
    arr[line.charCodeAt(i) - 65]++;
}
let max = 0
let maxIndex = 0;
let flag = 0;
for(let i = 0; i < 26; i++){
    if(arr[i]> max){
        max = arr[i];
        maxIndex = i; 
        flag = 0;
        }
    else if(arr[i] == max)
        flag = 1;   
}
if(flag == 1)
    console.log('?');
else
    console.log(String.fromCharCode(maxIndex + 65));
  rl.close();
}).on('close', function () {
  process.exit();
});