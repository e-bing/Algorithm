#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer, int cnt) {
    answer.push_back(cur);
    if (cnt == tickets.size()) return true;
    
    for (int i = 0 ; i < tickets.size(); i++) {
        if (visited[i] == true || tickets[i][0] != cur) continue;
        visited[i] = true;
        if (dfs(tickets[i][1], tickets, visited, answer, cnt + 1)) return true;
        visited[i] = false;
            
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, visited, answer, 0);
    
    
    return answer;
}