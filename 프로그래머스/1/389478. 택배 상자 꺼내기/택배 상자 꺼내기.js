function solution(n, w, num) {
    let answer = 0;
    
    // n : 상자의 개수, w : 한 줄에 들어가는 상자의 개수
    // num : 꺼내려는 택배 상자의 번호
    
    const topLine = Math.ceil(n / w);
    const topRow = (topLine % 2) ? ((n - 1) % w) : ((w - 1) - ((n - 1) % w));
    // 홀수일 경우 순방향 종료
    // 짝수일 경우 역방향 종료
    
    const targetLine = Math.ceil(num / w) 
    // 내가 찾는 상자가 몇번째 줄에 있는지 확인
    // targetLine이 홀수일 경우 순방향
    // targetLine이 짝수일 경우 역방향
    
    const targetRow = (targetLine % 2) ? ((num - 1) % w) : ((w - 1) - ((num - 1) % w));;
    
    console.log(targetRow, topRow)
    answer = topLine - targetLine;
    if (answer) {
        if (topLine % 2) {
            if (targetRow <= topRow) {
                answer++;
            }
        }
        else {
            if (targetRow >= topRow) {
                answer++;
            }
        }
    }
    else answer++;
    
    return answer;
}