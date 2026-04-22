#include <string>
#include <vector>
#include <cmath>

using namespace std;

void dfs(int n, int& answer, int depth, vector<int>& map) {
    if (depth == n) {
        answer++;
        return;
    }
    
    for (int i = 0 ; i < n ; i++) {
        bool flag = true;
        for (int j = 0 ; j < depth ; j++) {
            if (i == map[j] || abs(i - map[j]) == (depth - j)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            map[depth] = i;
            dfs(n, answer, depth + 1, map);
            map[depth] = -10;
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> map(n, -10);
    
    dfs(n, answer, 0, map);
    
    return answer;
}