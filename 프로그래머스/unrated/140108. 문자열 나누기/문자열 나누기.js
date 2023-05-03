function solution(s) {
    var answer = 0;
    var x = ""
    var count_x = 0;
    var not_x = 0;
    for (let i = 0 ; i < s.length ; i++) {
        if (!x) {
            x = s[i];
            count_x = 1;
            if (i + 1 === s.length) {
                answer += 1;
            }
        }
        else {
            if (s[i] === x) {
                count_x += 1;
            }
            else {
                not_x += 1;
            }
            if (count_x === not_x) {
                answer += 1;
                count_x = 0;
                not_x = 0;
                x = "";
            }
            else if (i + 1 === s.length) {
                answer += 1;
            }
        }
    }
    return answer;
}