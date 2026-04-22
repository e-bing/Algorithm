#include <string>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, bool>> q; 
    
    for (int i = 0; i < priorities.size() ; i++) {
        if (location == i) {
            q.push_back({priorities[i], true});
        }
        else {
            q.push_back({priorities[i], false});
        }
    }
    
    while (!q.empty()) {
        bool flag = false;
        pair<int, bool> cur = q.front();
        q.pop_front();
        for (auto next : q) {
            if (cur.first < next.first) {
                flag = true;
                break;
            }
        }
        if (flag) { 
            q.push_back(cur);
        }
        else {
            answer++;
            if (cur.second) break;
        }
    }
    
    return answer;
}