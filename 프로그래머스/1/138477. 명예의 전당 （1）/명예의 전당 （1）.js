function solution(k, score) {
    let answer = [];
    let hof = [];
    score.forEach(s => {
        hof.push(s);
        hof.sort((a,b) => b-a);
        if(hof.length > k) hof.pop();
        answer.push(hof.at(-1));
    })
    return answer;
}