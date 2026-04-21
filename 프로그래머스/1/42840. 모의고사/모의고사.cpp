#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int scores[3] = {0, 0, 0};
    int person1[] = {1, 2, 3, 4, 5};
    int person2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int person3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0 ; i < answers.size() ; i++) {
        if (answers[i] == person1[i % 5]) scores[0]++;
        if (answers[i] == person2[i % 8]) scores[1]++;
        if (answers[i] == person3[i % 10]) scores[2]++;
    }
    
    int top = *max_element(scores, scores + 3);
    for (int i = 0 ; i < 3 ; i++) {
        if (scores[i] == top) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}