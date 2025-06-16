function solution(food) {
    let answer = '';
    for(let i = 1; i < food.length; i ++) {
        let str = String(i);
        answer += str.repeat(food[i] / 2);
    };
    
    return answer + '0' + [...answer].reverse().join('');
}