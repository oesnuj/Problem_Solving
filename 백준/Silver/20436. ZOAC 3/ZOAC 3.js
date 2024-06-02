const fs = require('fs')
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');

const current = input[0].trim().split(' ');
const str = input[1];

const left = new Map();
const right = new Map();

// left 맵에 값 추가
left.set('q', { x: 0, y: 0 });
left.set('w', { x: 0, y: 1 });
left.set('e', { x: 0, y: 2 });
left.set('r', { x: 0, y: 3 });
left.set('t', { x: 0, y: 4 });
left.set('a', { x: 1, y: 0 });
left.set('s', { x: 1, y: 1 });
left.set('d', { x: 1, y: 2 });
left.set('f', { x: 1, y: 3 });
left.set('g', { x: 1, y: 4 });
left.set('z', { x: 2, y: 0 });
left.set('x', { x: 2, y: 1 });
left.set('c', { x: 2, y: 2 });
left.set('v', { x: 2, y: 3 });

// right 맵에 값 추가
right.set('y', { x: 0, y: 1 });
right.set('u', { x: 0, y: 2 });
right.set('i', { x: 0, y: 3 });
right.set('o', { x: 0, y: 4 });
right.set('p', { x: 0, y: 5 });
right.set('h', { x: 1, y: 1 });
right.set('j', { x: 1, y: 2 });
right.set('k', { x: 1, y: 3 });
right.set('l', { x: 1, y: 4 });
right.set('b', { x: 2, y: 0 });
right.set('n', { x: 2, y: 1 });
right.set('m', { x: 2, y: 2 });

let currentLeft = left.get(current[0]);
let currentRight = right.get(current[1]);

let count = 0;
for (let char of str) {
    count++;
    if (left.has(char)) {
        count += Math.abs(currentLeft.x - left.get(char).x) + Math.abs(currentLeft.y - left.get(char).y);
        currentLeft = left.get(char);
    } else if (right.has(char)) {
        count += Math.abs(currentRight.x - right.get(char).x) + Math.abs(currentRight.y - right.get(char).y);
        currentRight = right.get(char);
    }
}
console.log(count);