#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    int idx = 0;
    queue<int> q;
    for (int i = 0; i < bridge_length ; i++) {
        q.push(0);
    }
    
    while (!q.empty()) {
        answer++;
        current_weight -= q.front();
        q.pop();
        
        if (idx < truck_weights.size()) {
            
     
            if (current_weight + truck_weights[idx] <= weight) {
                current_weight += truck_weights[idx];
                q.push(truck_weights[idx]);
                idx++;
            }
            else {
                q.push(0);
            }
    }
        
        if (current_weight == 0 && idx == truck_weights.size()) break;
    }
    
    return answer;
}