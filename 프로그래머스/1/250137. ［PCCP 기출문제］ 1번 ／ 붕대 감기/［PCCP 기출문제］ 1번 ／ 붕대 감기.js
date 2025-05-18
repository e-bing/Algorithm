function solution(bandage, health, attacks) {
    // bandage : 시전 시간, 초당 회복량, 추가 회복량
    let answer = 0;
    let pHealth = health;
    let count = 0;
    let attackIdx = 0;
    
    const timeLine = [...Array(attacks[attacks.length - 1][0] + 1)].map((_, i) => i);
    
    for (const tSec of timeLine) {
        if (tSec === attacks[attackIdx][0]) {
            // 공격 들어오는 시간인 경우
            count = 0;
            pHealth -= attacks[attackIdx][1];
            attackIdx++;
            if (pHealth <= 0) break;
        }
        else {
            // 공격을 받지 않은 경우
            count++;
            if (count === bandage[0]) {
                count = 0;
                pHealth = Math.min(health, pHealth + bandage[1] + bandage[2]);
            }
            else {
                pHealth = Math.min(health, pHealth + bandage[1]);
            }
        }
    }
    
    answer = (pHealth <= 0) ? (-1) : (pHealth);
    
    return answer;
}