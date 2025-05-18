function solution(players, callings) {
    var answer = [...players];
    const idxMap = {};
    answer.forEach((name, idx) => {
        idxMap[name] = idx;
    })
    
    for (const calling of callings) {
        const index = idxMap[calling];
        const temp = answer[index - 1];
        answer[index - 1] = calling;
        answer[index] = temp;
        
        idxMap[calling] = index - 1;
        idxMap[temp] = index;
    }

    return answer;
}