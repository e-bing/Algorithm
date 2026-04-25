#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    pair<int, int> cur = {0, 0};
    pair<int, int> goal = {0, 0};
    int n = board.size(), m = board[0].size();
    vector<vector<int>> map(n);
    // 빈칸 0, 방문 n, 장애물 -1
    
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (board[i][j] == 'D') {
                map[i].push_back(-1);
            }
            else if (board[i][j] == 'R') {
                map[i].push_back(0);
                cur = {i, j};
            }
            else if (board[i][j] == 'G') {
                map[i].push_back(0);
                goal = {i, j};
            }
            else map[i].push_back(0);
        }
    }
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    
    queue<pair<int, int>> q;
    q.push(cur);
    int dist = 0;
    
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur == goal) {
            answer = map[cur.first][cur.second];
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            dist = 0;
            int nx = cur.first + dx[i] * (dist + 1);
            int ny = cur.second + dy[i] * (dist + 1);
            while (0 <= nx && nx < n && 0 <= ny && ny < m ) {
                if (map[nx][ny] == -1) break;
                dist++;
                nx = cur.first + dx[i] * (dist + 1);
                ny = cur.second + dy[i] * (dist + 1);
            }
            if (dist != 0) {
                nx = cur.first + dx[i] * dist;
                ny = cur.second + dy[i] * dist;
                if (map[nx][ny] == 0) {
                    map[nx][ny] = map[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    
    return answer;
}