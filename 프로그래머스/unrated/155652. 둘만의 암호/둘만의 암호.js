function solution(s, skip, index) {
    var answer = '';
    var alphabets = "abcdefghijklmnopqrstuvwxyz"
    var validAlpha = '';
    let sTemp = 0
    for (let i = 0 ; i < 26 ; i++) {
        if (!skip.includes(alphabets[i])) {
            validAlpha += alphabets[i]
        }
    }
    for (let i = 0 ; i < s.length ; i++) {
        sTemp = validAlpha.indexOf(s[i]) + index
        if (sTemp >= validAlpha.length) {
            sTemp = sTemp % validAlpha.length
        }
        answer += validAlpha[sTemp]
    }
    return answer;
}