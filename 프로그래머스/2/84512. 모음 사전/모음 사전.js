function solution(word) {
    const vowels = ['A','E','I','O','U'];
    const arr = [];
    dfs('');
    function dfs(str){
        if(str.length === 6) return;
        if (str) arr.push(str);
        
        for(const w of vowels){
            dfs(str + w);
        }
    }
    return arr.indexOf(word) + 1;
}


