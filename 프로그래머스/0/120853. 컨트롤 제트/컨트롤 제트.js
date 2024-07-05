function solution(s) {
    const input = s.split(' ');
    let stack = [];
    for(let i = 0; i < input.length; i++){
        if(input[i] === 'Z') stack.pop();
        else stack.push(+input[i]);
    }
    return stack.reduce((sum, e) => sum + e, 0);
}