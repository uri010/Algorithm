//
// Created by 김유리 on 2023/09/05.
//
#include <string>

using namespace std;

bool solution(string s) {
    int open_paren = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open_paren++;
        } else if (s[i] == ')') {
            if (--open_paren < 0) {
                return false;
            }
        }
    }
    if (open_paren != 0) return false;

    return true;
}