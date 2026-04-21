#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> adj(n + 1);
    for (auto& w : wires) {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    for(auto& exclude : wires) {
        int u = exclude[0];
        int v = exclude[1];
        
        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        int cnt = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int next : adj[cur]) {
                if ((cur == u && next == v) || (cur == v && next == u)) continue;
                
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    cnt++;
                }
            }
        }
        
        int diff = abs(cnt - (n - cnt));
        if (answer > diff) answer = diff;
    }
    
    return answer;
}