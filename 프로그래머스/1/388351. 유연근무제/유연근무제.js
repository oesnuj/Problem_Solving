function solution(schedules, timelogs, startday) {
    let answer = schedules.length;
    timelogs.forEach((log, index) => {
        let currentDay = startday;
        for(let i = 0; i < log.length; i++){
            //주말은 제외
            if (currentDay === 7 || currentDay === 6) {
                    currentDay = currentDay % 7 + 1;
                    continue;
                }
            //만약 지각이 한번이라도 있다면 상품 명단 제외 & 탈출
            let limitTime =  schedules[index] + 10
            if(limitTime.toString().substr(-2, 2) > 59){
                limitTime = limitTime + 100 - 60;
            } 
            
            if(log[i] > limitTime){
                console.log(index + "번 사원은 "+ currentDay +"요일에 " +  limitTime + "까지 출근해야하는데 " + log[i] + "에 출근");
                answer--;
                break;
                }
            currentDay = currentDay % 7 + 1;
        }
    })
    return answer;
}