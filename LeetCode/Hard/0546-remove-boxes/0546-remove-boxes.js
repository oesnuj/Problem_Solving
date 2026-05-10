function removeBoxes(boxes) {
    const n = boxes.length;

    // dp[left][right][streak]
    const dp = Array.from({length: n}, () => Array.from( { length: n }, () => Array(n).fill(-1)));

    function dfs(left, right, streak) {
        // 제거할 박스 없음
        if (left > right) {
            return 0;
        }

        // 이미 계산한 상태
        if (dp[left][right][streak] !== -1) {
            return dp[left][right][streak];
        }

        //case 1 : 현재 left를 지금 제거
        let result = (streak + 1) * (streak + 1) + dfs(left + 1, right, 0);

        //case 2 : 뒤의 같은 색과 합치기
        for (let m = left + 1; m <= right; m++) {
            if (boxes[m] === boxes[left]) 
                result = Math.max(result, dfs(left + 1, m - 1, 0) + dfs(m, right, streak + 1));
        }

        // 캐싱
        dp[left][right][streak] = result;

        return result;
    }

    return dfs(0, n - 1, 0);
}