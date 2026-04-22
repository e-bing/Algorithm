#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool diff(string a, string b) {
    bool flag = false;
    
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            if (!flag) flag = true;
            else return false;
        }
    }
    return flag;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int cur = words.size();
    words.push_back(begin);
    vector<vector<int>> map(words.size());
    vector<bool> visited(words.size(), false);
    
    for (int i = 0; i < words.size() - 1 ; i++) {
        for (int j = i + 1; j < words.size() ; j++) {
            if (diff(words[i], words[j])) {
                map[i].push_back(j);
                map[j].push_back(i);
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({cur, 0});
    visited[cur] = true;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if (words[cur.first] == target) {
            answer = cur.second;
            break;
        }
        
        for (auto x : map[cur.first]) {
            if (!visited[x]) {
                q.push({x, cur.second + 1});
                visited[x] = true;
            }
        }
        
    }
    
    return answer;
}