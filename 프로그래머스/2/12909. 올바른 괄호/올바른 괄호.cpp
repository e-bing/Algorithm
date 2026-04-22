#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> str;
    
    for (int i = 0 ; i < s.length(); i++) {
        if (s[i] == '(') {
            str.push(1);
        }
        else if (s[i] == ')') {
            if (str.empty()) {
                answer = false;
                break;
            }
            str.pop();
        }
    }
    
    if (!str.empty()) answer = false;
    

    return answer;
}