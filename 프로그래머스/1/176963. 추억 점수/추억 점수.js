function solution(name, yearning, photo) {
    let result = [];
    const nameMap = new Map();
    name.forEach((n, i) => {
        nameMap.set(n, yearning[i]);
    })
    
    photo.forEach(names => {
        let point = 0;
        names.forEach(n => {
            point += nameMap.get(n) ?? 0;
        })
        result.push(point);
    })
    return result;
}