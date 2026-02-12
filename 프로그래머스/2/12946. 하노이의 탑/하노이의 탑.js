function solution(n) {
    const answer = [];
    function recursion(a, b, n){
        if(n === 0) return;
        recursion(a, 6-a-b, n - 1);
        answer.push([a, b])
        recursion(6-a-b, b, n - 1);
    }
    recursion(1, 3, n);
    return answer;
}