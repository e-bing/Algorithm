#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    int x = 0;
    
    for (int j = 0 ; j < n ; j++ ) {
        
        if (!visited[j]) {
            q.push(j);
            visited[j] == true;
            answer++;

            while(!q.empty()) {
                x = q.front();
                q.pop();

                for (int i = 0; i < n ; i++) {
                    if (x != i && computers[x][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
    
    return answer;
}