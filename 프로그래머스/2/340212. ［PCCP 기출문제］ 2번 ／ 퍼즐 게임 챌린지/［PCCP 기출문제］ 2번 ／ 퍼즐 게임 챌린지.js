function puzzle(diffs, times, limit, level) {
    let time_sum = 0;
    for (let i = 0; i < diffs.length; i++) {
        if (diffs[i] <= level) {
            time_sum += times[i];
        } else {
            time_sum += (diffs[i] - level) * (times[i] +  (i > 0 ? times[i - 1] : 0)) + times[i];
        }
        if (time_sum > limit) return false;
    }
    return true;
}


function solution(diffs, times, limit) {
    let lo = 1;
    let hi = 100000;
    let answer = hi;
    
    while(lo <= hi){
        let mid = Math.floor((lo + hi) / 2);;
        if(puzzle(diffs, times, limit, mid)){
            answer = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return answer;
}