function dateParser(date){
    const [year, month, day] = date.split('.').map(Number);
    return {year , month, day};
}

function isExpired(today, base) {
  return (
      base.year < today.year ||
      (base.year === today.year && base.month < today.month) ||
      (base.year === today.year && base.month === today.month && base.day <= today.day)
  );
}


function solution(today, terms, privacies) {
    let answer= [];
    const validityByTerms = new Map();

    terms.forEach(t => {
        const [key, value] = t.split(' ');
        validityByTerms.set(key, Number(value));
    })
    
    privacies.forEach((p, index) => {
       const [date, term] = p.split(' ');
        let baseDate = dateParser(date);
        const todayDate = dateParser(today);
        const validity = validityByTerms.get(term);
        const totalMonths = baseDate.month + validity;
        
        baseDate.year += Math.floor((totalMonths - 1) / 12);
        baseDate.month = ((totalMonths - 1) % 12) + 1;
        
        if (isExpired(todayDate, baseDate)) {
          answer.push(index + 1);
        }
    })
    return answer;
}