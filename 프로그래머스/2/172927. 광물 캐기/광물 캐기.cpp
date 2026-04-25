#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int idx = 0;
    vector<pair<int, int>> new_minerals;
    int part_sum = 0;
    int picks_size = picks[0] + picks[1] + picks[2];
    
    for (idx = 0; idx < picks_size * 5 && idx < minerals.size() ; idx++) {
        if (idx != 0 && idx % 5 == 0) {
            new_minerals.push_back({part_sum, idx - 5});
            part_sum = 0;
        }
        if (minerals[idx] == "diamond") part_sum += 25;
        else if (minerals[idx] == "iron") part_sum += 5;
        else part_sum += 1;
    }
    if (part_sum > 0) {
    int last_start_idx = ((idx - 1) / 5) * 5;
    new_minerals.push_back({part_sum, last_start_idx});
}
    
    sort(new_minerals.rbegin(), new_minerals.rend());
    
    for (idx = 0; idx < new_minerals.size() ; idx++) {
        int i = new_minerals[idx].second;
        
        if (picks[0]) {
            for ( ; i < new_minerals[idx].second + 5 && i < minerals.size() ; i++) {
                answer++;
            }
            picks[0]--;
        }
        else if (picks[1]) {
            for ( ; i < new_minerals[idx].second + 5 && i < minerals.size() ; i++) {
                if (minerals[i] == "diamond") answer += 5;
                else answer++;
            }
            picks[1]--;            
        }
        else if (picks[2]) {
            for ( ; i < new_minerals[idx].second + 5 && i < minerals.size() ; i++) {
                if (minerals[i] == "diamond") answer += 25;
                else if (minerals[i] == "iron") answer += 5;
                else answer++;
            }
            picks[2]--;
        }
    }
    
    return answer;
}