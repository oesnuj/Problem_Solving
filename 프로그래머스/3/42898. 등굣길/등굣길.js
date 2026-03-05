function solution(m, n, puddles) {
    const dp = Array.from({length : n}, () => Array(m).fill(0));
    dp[0][0] = 1;
    const puddleSet = new Set(puddles.map(([x, y]) => `${y-1},${x-1}`));
    for(let i = 0; i < n; i ++){
        for(let j = 0; j < m; j++){
            if(puddleSet.has(`${i},${j}`)) continue;
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1_000_000_007;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1_000_000_007;
        }
    }
    return dp[n-1][m-1];
}