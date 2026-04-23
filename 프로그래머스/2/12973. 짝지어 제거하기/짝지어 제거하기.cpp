#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 1;
    stack<char> st;
    
    for (char x : s) {
        if (!st.empty()) {
            char prev = st.top();
            if (prev == x) {
                st.pop();
            }
            else {
                st.push(x);
            }
        }
        else {
            st.push(x);
        }
    }
    
    if (!st.empty()) answer = 0;

    return answer;
}