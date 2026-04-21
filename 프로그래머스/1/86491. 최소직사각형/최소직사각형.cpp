#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0, h = 0;
    
    for (auto& element : sizes) {
        if (element[0] < element[1]) {
            int temp = element[0];
            element[0] = element[1];
            element[1] = temp;
        }
        
        if (w < element[0]) w = element[0];
        if (h < element[1]) h = element[1];
    }
    
    answer = w * h;
    return answer;
}