#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    long long w, h;
    
    for (h = 1; h <= sqrt(brown + yellow) ; h++) {
        for (w = h ; w < brown + yellow ; w++) {
            if (w * h != brown + yellow) continue;
            if (brown == 2 * (w + h - 2) && yellow == (w - 2) * (h - 2)) {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
        if (answer.size() > 0) break;
    }
    
    return answer;
}