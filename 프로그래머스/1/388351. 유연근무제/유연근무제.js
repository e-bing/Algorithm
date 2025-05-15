function timeConverter(timelog) {
    var result = 0;
    
    result = Number(timelog) % 100;
    result += Math.floor(Number(timelog) / 100) * 60;
    return result;
}

function solution(schedules, timelogs, startday) {
    const n = schedules.length;
    
    var answer = 0;
    var convertedSchedule = 0;
    var flag = 0;
    
    // 1 -> 5, 6 / 2 -> 4, 5 / 3 -> 3, 4 / 4 -> 2, 3 
    // 5 -> 1, 2 / 6 -> 0, 1 / 7 -> 0, 6
    // (startday + i - 1) % 7 == 5 or 6
    
    for (var j = 0 ; j < n ; j++) {
        convertedSchedule = timeConverter(schedules[j]) + 10;
        flag = 1;
        for (var i = 0 ; i < 7 ; i++) {
            if ((startday + i - 1) % 7 == 5) continue;
            else if ((startday + i - 1) % 7 == 6) continue;
            
            if (timeConverter(timelogs[j][i]) > convertedSchedule) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            answer++;
        }
    }
        
    return answer;
}