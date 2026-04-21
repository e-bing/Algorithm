#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int cur = k;
        int cleared = 0;
        for (int i = 0 ; i < dungeons.size(); i++) {
           if (dungeons[i][0] <= cur) {
               cur -= dungeons[i][1];
               cleared++;
           }
            else {
                break;
            }
       } 
        if (answer < cleared) answer = cleared;
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}