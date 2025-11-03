function solution(answers) {
    const person1 = [1, 2, 3, 4, 5];
    const person2 = [2, 1, 2, 3, 2, 4, 2, 5];
    const person3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    const scores = {
        1 : 0,
        2 : 0,
        3 : 0
    }
    answers.forEach((e, i) => {
        if(person1[i % person1.length] === e) scores[1]++;
        if(person2[i % person2.length] === e) scores[2]++;
        if(person3[i % person3.length] === e) scores[3]++;
    })
    const max = Math.max(...Object.values(scores));
    const result = Object.keys(scores)
        .filter(key => scores[key] === max).map(Number);
    
    return result;
}