function sequence(k) {
    const result = [];
    let x = 0;
    
    while (k > 1) {
        result.push([x, k]);
        x++;
        if (k % 2) {
            k = k * 3 + 1;
        }
        else {
            k = k / 2;
        }
    }
    result.push([x, 1]);
    return result;
}

function check(range, area) {
    if (range[0] < 0 || range[1] < 0) {
        return -1.0;
    }
    else if (range[0] > range[1]) {
        return -1.0;
    }
    return area[range[1]] - area[range[0]];
}

function solution(k, ranges) {
    var answer = [];
    let temp = 0;
    const sequences = sequence(k);
    const len = sequences.length - 1;
    const area = [0];
    
    for (let i = 1 ; i < sequences.length ; i++) {
        temp += (sequences[i - 1][1] + sequences[i][1]) / 2;
        area.push(temp);
    }
    for (let j = 0 ; j < ranges.length ; j++) {
        temp = check([ranges[j][0], len + ranges[j][1]], area);
        answer.push(temp);
    }
    return answer;
}