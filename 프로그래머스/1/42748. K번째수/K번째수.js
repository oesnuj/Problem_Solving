function solution(array, commands) {
    const answer = [];
    commands.forEach(e => {
        const [st, en, k] = e;
        const a = array.slice(st - 1, en).sort((a, b) => a - b);
        answer.push(a[k - 1]);
    })
    return answer;
}