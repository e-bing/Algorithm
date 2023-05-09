function solution(number, limit, power) {
    var answer = 0;
    var divisor = [];
    
    for (let j = 1 ; j < number + 1 ; j++) {
        divisor = [];
        
        for (let i = 1 ; i < Math.sqrt(j) ; i++) {
            if (j % i === 0) {
                divisor.push(i);
                divisor.push(j / i);
            }
        }
        if (j % Math.sqrt(j) === 0) {
            divisor.push(Math.sqrt(j));
        }
        if (divisor.length > limit) {
            answer += power;
        }
        else {
            answer += divisor.length;
        }
    }
    return answer;
}