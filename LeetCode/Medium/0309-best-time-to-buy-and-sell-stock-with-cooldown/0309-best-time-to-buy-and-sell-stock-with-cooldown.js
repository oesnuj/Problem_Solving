/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    // 1. 테이블 정의하기
    // dp[i][state] : i번째 날까지 행동을 했을 때, i번째 날의 최종 상태가 state인 경우의 최대 이익
    // hold(0), sold(1), rest(2)

    // 2. 점화식 세우기
    // i일 끝났을 때 주식을 들고 있음
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - price[i])

    // i일 끝났을 때 오늘 막 판매함
    // dp[i][1] = dp[i - 1][0] + price[i]

    // i일 끝났을 때 아무것도 안 하고 쉬는 상태
    // dp[i][2] = max(dp[i - 1][2], dp[i - 1][1])

    // 3. 초기값 세우기
    // dp[0][0] : -price[0]
    // dp[0][1] : -Infinity
    // dp[0][2] : 0

    const N = prices.length;
    const dp = Array.from({ length: N }, () => Array(3).fill(0));
    dp[0][0] = -prices[0];
    dp[0][1] = -Infinity;

    for(let i = 1; i < N; i++){
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][2] - prices[i])
        dp[i][1] = dp[i - 1][0] + prices[i]
        dp[i][2] = Math.max(dp[i - 1][2], dp[i - 1][1])
    }

    return Math.max(...dp[N - 1])
};