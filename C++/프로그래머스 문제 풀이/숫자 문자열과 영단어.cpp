//
// Created by 김유리 on 2023/11/14.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    string answer;
    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
            answer += s[i];
        }
        for (int j = 0; j < 10; j++) {
            if (s[i] == numbers[j][0] && s[i + 1] == numbers[j][1]) {
                answer += to_string(j);
                i += numbers[j].size() - 1;
                break;
            }
        }
    }
    int num = stoi(answer);
    return num;
}