const fs = require('fs')
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().split('\n');
const n = +input[0];
let arr = input[1].split(' ').map(Number);
const m = +input[2];
let operations = [];
for (let i = 0; i < m; i++) {
    let operation = input[3 + i].split(' ').map(Number);
    operations.push(operation);
}

function changeArr(){
    for(let i = 0; i< m; i++){
        const gender = operations[i][0];
        const num = operations[i][1];
        if(gender == 1){
            for (let j = num; j <= n; j += num)
                {
                    arr[j - 1] = arr[j - 1] === 1 ? 0 : 1;
                }
            }
        else if(gender == 2){
            let index = num - 1;
            arr[index] = arr[index] === 1 ? 0 : 1;
            for (let j = 1; index - j >= 0 && index + j < n; ++j)
            {
                if (arr[index - j] == arr[index + j])
                {
                    arr[index - j] = arr[index - j] === 1 ? 0 : 1;
                    arr[index + j] = arr[index + j] === 1 ? 0 : 1;
                }
                else
                {
                    break;
                }
            }
        }
    }

}

function PrintResult()
{
    let result = '';
    for (let i = 0; i < n; i++) {
        result += arr[i] + ' ';
        if ((i + 1) % 20 === 0) {
            result += '\n';
        }
    }
    console.log(result.trim());
}

changeArr();
PrintResult();