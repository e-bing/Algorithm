#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int convert_time(string a) {
    return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> left;
    vector<int> timeline;
    vector<pair<string, int>> subjects;
    int cur = 0;
    
    sort(plans.begin(), plans.end(), [] (const vector<string>& a, const vector<string>& b) {
        int time_a = convert_time(a[1]);
        int time_b = convert_time(b[1]);
        return time_a < time_b;
    });
    
    for (auto p : plans) {
        timeline.push_back(convert_time(p[1]));
        subjects.push_back({p[0], stoi(p[2])});
    }
    
    timeline.push_back(1439);
    
    for (int i = 0 ; i < timeline.size() - 1; i++) {
        int left_time = timeline[i + 1] - subjects[i].second - timeline[i];
        if (left_time == 0) {
            answer.push_back(subjects[i].first);
        }
        else if (left_time < 0) {
            left.push({subjects[i].first, abs(left_time)});
        }
        else {
            answer.push_back(subjects[i].first);
            while (!left.empty() && left_time >= 0) {
                auto a = left.top();
                left.pop();
                left_time -= a.second;
                if (left_time >= 0) answer.push_back(a.first);
                else left.push({a.first, abs(left_time)});
            }
        }
    }
    
    while (!left.empty()) {
        auto b = left.top();
        left.pop();
        answer.push_back(b.first);
    }
    
    return answer;
}