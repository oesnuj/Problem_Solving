const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = require('fs').readFileSync(filepath).toString().trim().split('\n');

const cheeseList = input[1].trim().split(' ');
const uniqueCheeseList = [...new Set(cheeseList)];

let cnt = 0;
for (const cheese of uniqueCheeseList) {
    if (cheese.endsWith("Cheese")) {
        cnt++;
        if (cnt >= 4) {
            console.log("yummy");
            return;
        }
    }
}
console.log("sad");