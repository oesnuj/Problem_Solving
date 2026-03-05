
function solution(n, computers) {
    const visited = Array(n).fill(false);
    let cnt = 0;
    for(let i = 0; i < n ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        const queue = [i];
        let head = 0;
        while(head < queue.length){
            const cur = queue[head++];
            computers[cur].forEach((connected, nxt) =>{
                    if(connected === 1 && !visited[nxt]){
                    queue.push(nxt);
                    visited[nxt] = true;
                }
            })
        }
        cnt++;
    }
    return cnt;
}