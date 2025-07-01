function solution(fees, records) {
    const [defaultTime, defaultFee, unitTime, unitFee] = fees;
    const carMap = new Map();
    records.forEach(r =>{
        const [time, carNumber, accessType] = r.split(' ');
        const [hour, minute] = time.split(':').map(Number);
        const totalMinute = hour * 60 + minute;
        
        const carDatas = carMap.get(carNumber);
        if(carDatas)
            carDatas.push([totalMinute, accessType])
        else{
            carMap.set(carNumber, [[totalMinute, accessType]]);
        }
    })
    
    const resultMap = new Map();
    const defaultExitTime = 23 * 60 + 59;
    carMap.forEach((value, key) => {
        let prevType;
        let prevTime = 0;
        let total = 0;
        value.forEach(timeAndAccessType => {
            const [time, type] = timeAndAccessType;
            if (type === 'IN' && prevType === 'IN') {
               total += defaultExitTime - prevTime;
            }

            if (type === 'OUT' && prevType === 'IN') {
              total += time - prevTime;
            }

            prevType = type;
            prevTime = time;
            resultMap.set(key, total);    
        })
        
        if (prevType === 'IN') {
          resultMap.set(key, resultMap.get(key) + (defaultExitTime - prevTime));
        }
        const totalTime = resultMap.get(key);
        let fee = defaultFee;
        if (totalTime > defaultTime) {
          const extra = totalTime - defaultTime;
          const units = Math.ceil(extra / unitTime);
          fee += units * unitFee;
        }

        resultMap.set(key, fee);
      });
    
    const answer = [...resultMap.keys()].sort().map(key => resultMap.get(key));
    return answer;
}