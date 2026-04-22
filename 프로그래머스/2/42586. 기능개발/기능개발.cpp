#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> q;
    int day = 1;
    int complete = 0;
    
    for (int i = 0 ; i < progresses.size(); i++) {
        q.push({progresses[i], speeds[i]});
    }
    
    while (!q.empty()) {
        pair<int, int> p = q.front();
        if (p.first + p.second * day >= 100) {
            q.pop();
            complete++;
        }
        else {
            if (complete != 0) answer.push_back(complete);
            complete = 0;
            day++;
        }
    }
    if (complete != 0) answer.push_back(complete);
    
    return answer;
}