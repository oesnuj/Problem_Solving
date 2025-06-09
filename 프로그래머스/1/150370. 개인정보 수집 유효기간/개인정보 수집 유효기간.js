function convertToDays(date){
    const [year, month, day] = date.split('.').map(Number);
    return year * 12 * 28 + month * 28 + day;
}

function solution(today, terms, privacies) {
    let answer= [];
    const validityByTerms = new Map();
    const todayDate = convertToDays(today);

    terms.forEach(t => {
        const [key, value] = t.split(' ');
        validityByTerms.set(key, Number(value));
    })
    
    privacies.forEach((p, index) => {
       const [date, term] = p.split(' ');
        const validity = validityByTerms.get(term);
        const expiryDate = convertToDays(date) + validity * 28;
        if(expiryDate <= todayDate){
            answer.push(index + 1)
        }
    })
    return answer;
}