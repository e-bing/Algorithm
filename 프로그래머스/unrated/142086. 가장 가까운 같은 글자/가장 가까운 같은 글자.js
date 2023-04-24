function solution(s) {
    var answer = [];
    var temp = {}
    for (let i = 0 ; i < s.length ; i++) {
        if (Object.keys(temp).includes(s[i])) {
            answer.push(i - temp[s[i]])
            temp[s[i]] = i
        }
        else {
            answer.push(-1)
            temp[s[i]] = i
        }
    }
    return answer;
}