function solution(numbers, target) {
    let count = 0;
    function recursion(i, sum){
        if(i === numbers.length){
           if(sum === target) count++;
            return;
       }
        recursion(i+1, sum + numbers[i])
        recursion(i+1, sum - numbers[i])
    }
    
    recursion(0, 0);
    return count;
}


