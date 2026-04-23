#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    char prev = ' ';
    
    for (char& x : s) {
        if (prev == ' ' && x != ' ') {
            if (islower(x)) {
                x = toupper(x);
            }
        }
        else if (prev != ' ' && x != ' ' && isupper(x)) x = tolower(x);
        prev = x;
    }
    answer = s;
    
    return answer;
}