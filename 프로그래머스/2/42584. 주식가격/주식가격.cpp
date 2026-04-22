#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0 ; i < prices.size() - 1 ; i++) {
        int cnt = 0;
        for (int j = i + 1 ; j < prices.size() ; j++) {
            cnt = j - i;
            if (prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    answer.push_back(0);
    
    return answer;
}