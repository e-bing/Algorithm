#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int answer = 0;
string alphabets = "AEIOU";
string target = "";

void dfs(string current) {
    if (target == current) {
        answer = cnt;
        return;
    }
    if (current.length() >= 5) return ;
    
    for (int i = 0 ; i < 5 ; i++) {
        cnt++;
        dfs(current + alphabets[i]);
        if (answer != 0) return ;
    }
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}