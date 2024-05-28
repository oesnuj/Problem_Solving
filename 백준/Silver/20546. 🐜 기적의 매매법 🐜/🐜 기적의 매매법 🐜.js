const fs = require('fs')
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().split('\n');
const seedMoney = +input[0];
const arr = input[1].split(' ').map(Number);

let jMoney = seedMoney;
let sMoney = seedMoney;
let jStock = 0;
let sStock = 0;


function buyStock(money, price, stock)
{
    while(money >= price){
        stock++;
        money -= price;
    }
    return [money, stock]
}

function sellStock(money, price, stock)
{
    while(stock > 0){
        stock--;
        money += price;
    }
    return [money, stock]
}

for(let i = 0; i < 14; i++){
    [jMoney, jStock] = buyStock(jMoney, arr[i], jStock);
    if(i > 2){
        if(arr[i - 3] < arr[i - 2] && arr[i - 2] < arr[i - 1]) //3일 연속 증가
            [sMoney, sStock] = sellStock(sMoney, arr[i], sStock);

        if(arr[i - 3] > arr[i - 2] && arr[i - 2] > arr[i - 1]) //3일 연속 하락
            [sMoney, sStock] = buyStock(sMoney, arr[i], sStock);
    }
}
const jResult = jMoney + jStock * arr[13]; 
const sResult = sMoney + sStock * arr[13];

if (jResult > sResult)
    console.log("BNP");
else if (jResult < sResult)
    console.log("TIMING");
else
    console.log("SAMESAME");