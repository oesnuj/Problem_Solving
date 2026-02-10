const dir = [[1, 0],[-1, 0],[0, 1],[0, -1]];

function solution(maps) {
    const m = maps.length;
    const n = maps[0].length;
    var answer = 0;
    
    if (maps[0][0] === 0) return -1;
    const queue = [[0, 0]];
    let head = 0;
    
    while(head < queue.length){
        const [x, y] = queue[head++];
        
        for (const [dx, dy] of dir){
            const nx = x + dx;
            const ny = y + dy;  
            if (nx >= 0 && nx < maps.length && ny >= 0 && ny < maps[0].length && maps[nx][ny] === 1) {
                maps[nx][ny] = maps[x][y] + 1;
                queue.push([nx, ny]);
            }
        }
    }
    
    
    return maps[m-1][n-1] === 1 ? -1 : maps[m-1][n-1];
}