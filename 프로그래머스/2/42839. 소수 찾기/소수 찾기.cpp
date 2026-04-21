#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool check_prime(int n) {
    bool result = true;
    
    if (n == 0 || n == 1) return false;
    for (int i = 2 ; i < n ; i++) {
        if (n % i == 0) {
            result = false;
            break;
        }
    }
    
    return result;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        for(int i = 1 ; i < numbers.size() + 1; i++) {
            cout << numbers.substr(0, i) << " ";
            s.insert(stoi(numbers.substr(0, i)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    for (const auto& n : s) {
        if (check_prime(n)) answer++;
    }
    
    return answer;
}