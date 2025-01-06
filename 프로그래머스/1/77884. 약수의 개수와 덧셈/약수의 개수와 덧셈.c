#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;
    int root_num = 0;
    
    for (int i = left ; i <= right ; i++) {
        root_num = sqrt(i);
        
        if (i == root_num * root_num) {
            answer -= i;
        }
        else answer += i;
    }
    return answer;
}