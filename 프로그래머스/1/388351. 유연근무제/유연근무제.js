const timeConverter = timelog => {
    const time = Number(timelog);
    return (time % 100) + Math.floor(time / 100) * 60;
}

function solution(schedules, timelogs, startday) {
    let answer = 0;
    
    answer = schedules.filter((schedule, j) => {
        const convertedSchedule = timeConverter(schedule) + 10;
        
        const isValid = timelogs[j].every((log, i) => {
            const day = (startday + i - 1) % 7;
            if (day === 5 || day === 6) return true;
            return timeConverter(log) <= convertedSchedule;
        })
        return isValid;
    }).length;
    
    return answer;
}