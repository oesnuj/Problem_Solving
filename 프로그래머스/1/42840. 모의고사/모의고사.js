function solution(answers) {
    const person1 = [1, 2, 3, 4, 5];
    const person2 = [2, 1, 2, 3, 2, 4, 2, 5];
    const person3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    const scores = [0, 0, 0]
    const result = [];
    
    answers.forEach((e, i) => {
        if(person1[i % person1.length] === e) scores[0]++;
        if(person2[i % person2.length] === e) scores[1]++;
        if(person3[i % person3.length] === e) scores[2]++;
    })
    const max = Math.max(...scores);
    
    scores.forEach((score, idx) => {
        if (score === max) {
            result.push(idx + 1);
        }
    });
    return result;
}