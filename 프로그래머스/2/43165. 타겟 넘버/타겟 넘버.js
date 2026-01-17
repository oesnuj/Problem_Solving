function solution(numbers, target) {
    function dfs(i, sum){
        if(i === numbers.length){
            return sum === target ? 1 : 0;
        }
        return dfs(i + 1, sum + numbers[i]) + dfs(i + 1, sum - numbers[i]);
    }
    
    return dfs(0, 0);
}