function solution(today, terms, privacies) {
    var answer = [];
    var termsSplit = {};
    var tempSplit = [];
    var todaySplit = today.split('.').map(Number);
    var todayCvt = todaySplit[0] * 336 + todaySplit[1] * 28 + todaySplit[2];
    var tempCvt = 0;
    
    for (let i = 0 ; i < terms.length ; i++) {
        termsSplit[terms[i].split(' ')[0]] = terms[i].split(' ')[1] * 1
    }
    for (let i = 0 ; i < privacies.length ; i++) {
        tempSplit = privacies[i].split(' ')[0].split('.').map(Number)
        // privaciesSplit.push(privacies[i].split(' ')[1])
        tempCvt = tempSplit[0] * 336 + tempSplit[1] * 28 + tempSplit[2];
        if (todayCvt > tempCvt + (termsSplit[privacies[i].split(' ')[1]] * 28 - 1)) {
            answer.push(i + 1)
        }
    }
    return answer;
}