function solution(answers) {
    var answer = [];
    const person1 = [1, 2, 3, 4, 5]
    const person2 = [2, 1, 2, 3, 2, 4, 2, 5]
    const person3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    let answer1 = 0;
    let answer2 = 0;
    let answer3 = 0;
    
    for (let i = 0 ; i < answers.length ; i++) {
        if (answers[i] === person1[i % 5]) answer1 += 1;
        if (answers[i] === person2[i % 8]) answer2 += 1;
        if (answers[i] === person3[i % 10]) answer3 += 1;
    }
    const maxValue = Math.max(answer1, answer2, answer3)
    if (answer1 === maxValue) answer.push(1)
    if (answer2 === maxValue) answer.push(2)
    if (answer3 === maxValue) answer.push(3)
    return answer;
}