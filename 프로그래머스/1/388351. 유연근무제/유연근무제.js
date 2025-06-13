function solution(schedules, timelogs, startday) {
    let answer = schedules.length;
    
    function getLimitTime(time) {
        let hour = Math.floor(time / 100);
        let minute = time % 100;

        minute += 10;
        if (minute >= 60) {
            hour += 1;
            minute -= 60;
        }
        return hour * 100 + minute;
    }

    function nextDay(day) {
        return day % 7 + 1;
    }
    
    
    timelogs.forEach((log, index) => {
        let currentDay = startday;
        const limitTime = getLimitTime(schedules[index]);

        for(let i = 0; i < log.length; i++){
            if (currentDay === 6 || currentDay === 7) {
                    currentDay = nextDay(currentDay);
                    continue;
                }
            
            if(log[i] > limitTime){
                answer--;
                break;
                }
            
            currentDay = nextDay(currentDay);
        }
    })
    return answer;
}