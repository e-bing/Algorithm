function solution(k, score) {
    let answer = [];
    let arr = [];
    let arrLen = 0;
    
    for (const dayScore of score) {
        if (arrLen === 0) {
            arr.push(dayScore);
            arrLen++;
        }
        else if (arrLen < k) {
            arr.push(dayScore);
            arr.sort((a, b) => b - a);
            arrLen++;
        }
        else {
            if (arr[k - 1] < dayScore) {
                arr[k - 1] = dayScore;
                arr.sort((a, b) => b - a);
            }
            
        }
        answer.push(arr[arrLen - 1]);
    }
    
    return answer;
}