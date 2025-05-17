const strToTime = (timeStr) => {
    const arr = timeStr.split(':').map(Number);
    return arr[0] * 60 + arr[1];
}

const timeToStr = (timeNum) => {
    const tMin = String(Math.floor(timeNum / 60));
    const tSec = String(timeNum % 60);
    return tMin.padStart(2, '0') + ':' + tSec.padStart(2, '0');
}

function solution(video_len, pos, op_start, op_end, commands) {
    // video_len : 동영상의 길이, pos : 재생위치 문자열
    // op_start : 오프닝 시작 시간, op_end : 종료 시간
    // commands : 사용자의 입력
    let answer = '';
    let posTime = strToTime(pos);
    
    const lenTime = strToTime(video_len);
    const startTime = strToTime(op_start);
    const endTime = strToTime(op_end);
    
    commands.forEach(command => {
        if ((posTime >= startTime) && (posTime < endTime)) posTime = endTime;
        if (command === 'prev') {
            posTime -= 10;
            if (posTime < 0) posTime = 0;
        }
        else {
            posTime += 10;
            if (posTime > lenTime) posTime = lenTime;
        }
    })
    
    if ((posTime >= startTime) && (posTime < endTime)) posTime = endTime;
    
    answer = timeToStr(posTime);
    
    return answer;
}