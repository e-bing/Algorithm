function solution(numbers) {
    var answer = [];
    var bigNums = [];
    var len = 0;
    
    for (let i = numbers.length - 1 ; i >= 0 ; i--) {
        while (len && (bigNums[len - 1] <= numbers[i])) {
            bigNums.pop();
            len--;
        }
        if (len) {
            answer.push(bigNums[len - 1]);
            bigNums.push(numbers[i]);
            len++;
        }
        else {
            answer.push(-1);
            bigNums.push(numbers[i]);
            len++;
        }
    }
    return answer.reverse();
}