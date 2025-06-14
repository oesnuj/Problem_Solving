function solution(participant, completion) {
    const map = new Map();
    completion.forEach(c => {
        if(map.has(c)){
            map.set(c, map.get(c) + 1);
        }
        else
            map.set(c, 1);
    })
    for (const p of participant) {
        const count = map.get(p);
        if (!count) {
            return p;
        }
        map.set(p, count - 1);
    }
}