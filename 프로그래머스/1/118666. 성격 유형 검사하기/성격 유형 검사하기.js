const scoreMap = [ 0, 3, 2, 1, 0 , 1, 2, 3];
const typeMap = {
    R: 0, T: 0,
    C: 0, F: 0,
    J: 0, M: 0,
    A: 0, N: 0,
};

function solution(survey, choices) {
    survey.forEach((q, i) => {
        const [target, partner] = q.split('');
        if(choices[i] <= 4)
            typeMap[target] += scoreMap[choices[i]];
        else 
            typeMap[partner] += scoreMap[choices[i]];
    })
    console.log(typeMap)
    const types = Object.keys(typeMap);
    let answer = '';
    for(let i = 0; i<types.length; i += 2){
        const a = types[i];
        const b = types[i+1];
        if(typeMap[a] > typeMap[b]) answer += a;
        else if(typeMap[a] < typeMap[b]) answer += b;
        else answer += a < b ? a : b
    }
    return answer;
}