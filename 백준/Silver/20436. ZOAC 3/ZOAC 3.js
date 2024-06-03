const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');

const [leftStart, rightStart] = input[0].trim().split(' ');
const str = input[1];

const left = new Map([
    ['q', { x: 0, y: 0 }], ['w', { x: 0, y: 1 }], ['e', { x: 0, y: 2 }], ['r', { x: 0, y: 3 }], ['t', { x: 0, y: 4 }],
    ['a', { x: 1, y: 0 }], ['s', { x: 1, y: 1 }], ['d', { x: 1, y: 2 }], ['f', { x: 1, y: 3 }], ['g', { x: 1, y: 4 }],
    ['z', { x: 2, y: 0 }], ['x', { x: 2, y: 1 }], ['c', { x: 2, y: 2 }], ['v', { x: 2, y: 3 }]
]); 

const right = new Map([
    ['y', { x: 0, y: 1 }], ['u', { x: 0, y: 2 }], ['i', { x: 0, y: 3 }], ['o', { x: 0, y: 4 }], ['p', { x: 0, y: 5 }],
    ['h', { x: 1, y: 1 }], ['j', { x: 1, y: 2 }], ['k', { x: 1, y: 3 }], ['l', { x: 1, y: 4 }],
    ['b', { x: 2, y: 0 }], ['n', { x: 2, y: 1 }], ['m', { x: 2, y: 2 }]
]);

let currentLeft = left.get(leftStart);
let currentRight = right.get(rightStart);

let count = 0;
for (const char of str) {
    count++;
    if (left.has(char)) {
        const newLeft = left.get(char);
        count += Math.abs(currentLeft.x - newLeft.x) + Math.abs(currentLeft.y - newLeft.y);
        currentLeft = newLeft;
    } else if (right.has(char)) {
        const newRight = right.get(char);
        count += Math.abs(currentRight.x - newRight.x) + Math.abs(currentRight.y - newRight.y);
        currentRight = newRight;
    }
}

console.log(count);
