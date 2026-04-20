#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (maps[nx][ny] == 1)
                {
                    maps[nx][ny] = maps[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    if (maps[n - 1][m - 1] == 1) {
        answer = -1;
    }
    else {
        answer = maps[n - 1][m - 1];
    }
    
    return answer;
}