function solution(id_list, report, k) {
    var answer = [];
    let users = {};
    const result = {};
    id_list.forEach(id => {
      result[id] = 0;
    });
    report.forEach(r => {
        const [reporter, user] = r.split(' ');
        if (!users[user]) {
            users[user] = new Set();
        }
    users[user].add(reporter);
    })
    
    
    for(key in users){
        if(users[key].size >= k){
            users[key].forEach(u => {
                result[u] += 1;
            })
        }
    }
    return Object.values(result);;
}