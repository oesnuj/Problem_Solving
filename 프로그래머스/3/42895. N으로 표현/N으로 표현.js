function solution(N, number) {
    var answer = 0;
    const dp = Array.from({length : 9}, () => new Set);
    dp[1] = [N];
    if(N === number) return 1;

    // dp[i] : N을 i번 사용해서 만들 수 있는 숫자 집합들 
    for(let i = 2; i < 9; i++){
        dp[i].add(Number(N.toString().repeat(i)));
        for(let j = i - 1; j > 0; j--){
            dp[j].forEach(a =>  {
                dp[i - j].forEach(b => {
                    dp[i].add(a + b);
                    dp[i].add(a - b);
                    dp[i].add(a * b);
                    dp[i].add(Math.trunc(a / b));
                })
            })
        }
        if(dp[i].has(number)) return i;
    }
    return -1;
}

// 1번 사용 5
// 2번 사용 55 or (5 와 5)의 연산
// 3번 사용 555 or 55와 5의 연산, 5와 55의 연산, 5와 5와 5의 연산(이미 해결한 문제)
