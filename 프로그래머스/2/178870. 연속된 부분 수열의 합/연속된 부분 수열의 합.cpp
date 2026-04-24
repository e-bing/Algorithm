#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    vector<int> answer = {0, n - 1};
    int left = 0, right = 0;
    int sum = sequence[0];
    
    while (left <= right && right < n) {
        if (sum < k) {
            if (++right < n) sum += sequence[right];
        }
        if (sum > k) {
            sum -= sequence[left];
            left++;
        }
        if (sum == k) {
            int cur_len = right - left;
            int best_len = answer[1] - answer[0];
            
            if (cur_len < best_len) answer = {left, right};
            
            if (++right < n) sum += sequence[right];
        }
    }
    
    
    
    return answer;
}