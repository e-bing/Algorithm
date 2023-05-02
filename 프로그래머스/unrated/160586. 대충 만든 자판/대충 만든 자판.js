function solution(keymap, targets) {
    var answer = [];
    var keymapsCount = {}
    let tempCount = 0
    for (let i = 0 ; i < keymap.length ; i++) {
        for (let j = 0 ; j < keymap[i].length ; j++) {
            if (Object.keys(keymapsCount).includes(keymap[i][j])) {
                if (j < keymapsCount[keymap[i][j]]) {
                    keymapsCount[keymap[i][j]] = j + 1
                }
            }
            else {
                keymapsCount[keymap[i][j]] = j + 1
            }
        }
    }
    
    for (let i = 0 ; i < targets.length ; i++) {
        tempCount = 0
        for (let j = 0 ; j < targets[i].length ; j++) {
            if (Object.keys(keymapsCount).includes(targets[i][j])) {
                tempCount += keymapsCount[targets[i][j]]
            }
            else {
                tempCount = -1
                break
            }
        }
        answer.push(tempCount)
    }
    return answer;
}