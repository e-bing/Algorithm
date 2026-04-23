#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int cnt = 0, i = 0;
    bool flag = true;
    auto max_num = max_element(arr.begin(), arr.end());
    
    while (flag) {
        cnt++;
        answer = (*max_num) * cnt;
        for (i = 0; i < arr.size(); i++) {
            if (answer % arr[i]) break;
        }
        if (i == arr.size() && answer % arr[i - 1] == 0) flag = false;
    }
    
    
    return answer;
}