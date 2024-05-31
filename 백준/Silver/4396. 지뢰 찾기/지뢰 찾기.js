const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().split('\n');

const n = parseInt(input.shift());
const mines = input.slice(0, n).map(line => line.split(''));
const opend = input.slice(n, 2 * n).map(line => line.split(''));

let hitMine = false;
const dr = [0, -1, 0, 1, -1, -1, 1, 1];
const dc = [1, 0, -1, 0, 1, -1, 1, -1];

function main(){
    for (let i = 0; i < n; i++){
        for (let j = 0; j < n; j++){
            if (opend[i][j] == 'x') //사용자가 연 보드판이라면
                opend[i][j] = checkMine(i, j); //해당 위치 8방향의 지뢰갯수 표시
        }
    }
    if (hitMine) //사용자가 지뢰를 밟았다면
        {
            for (let i = 0; i < n; i++) {
                for (let j = 0; j < n; j++) {
                    if (mines[i][j] === '*')
                        opend[i][j] = '*';  //모든 지뢰 공개하기
                }
            }
        }
    for (let i = 0; i < n; i++) { // 결과 보드판 출력
        console.log(opend[i].join('')); 
    }
}

    
function checkMine(r, c) //해당위치로부터 8방향(상, 하, 좌, 우, 대각선)의 지뢰갯수 반환
{
    if (mines[r][c] === '*')//지뢰를 밟았다면
    {
        hitMine = true;
        return '*';
    }

    let count = 0;
    for (let i = 0; i < 8; i++) {
        let nr = r + dr[i], nc = c + dc[i];
        if ( nr < 0 || nc < 0 ||nr >= n || nc >= n) continue;
        if (mines[nr][nc] === '*') count++;
    }
    return count;
}

main();