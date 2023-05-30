function solution(k, tangerine) {
    var answer = 0;
    const tangerines = [];
    const tan_keys = [];
    const tan_sort = tangerine.sort();
    for (let i = 0 ; i < tan_sort.length ; i++) {
        if (tan_keys.includes(tan_sort[i])) {
            tangerines[tan_keys.indexOf(tan_sort[i])][1]++;
        }
        else {
            tan_keys.push(tan_sort[i]);
            tangerines.push([tan_sort[i], 1]);
        }
    }
    const tangerines_sort = tangerines.sort(function(a, b) {
        return b[1] - a[1];
    })
    let temp = 0;
    for (let j = 0 ; j < tangerines_sort.length ; j++) {
        temp += tangerines[j][1];
        answer += 1;
        if (temp >= k) {
            break;
        }
    }
    return answer;
}