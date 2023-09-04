//
// Created by 김유리 on 2023/09/04.
//
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;

    int num = 2;
    int round = 1;
    bool flag = false;
    m.insert({words[0], 0});

    for (int i = 0; i < words.size() - 1; i++) {
        string prev = words[i];
        string cur = words[i + 1];

        if (m.find(cur) != m.end() || prev[prev.size() - 1] != cur[0]) {
            answer.push_back(num);
            answer.push_back(round);
            flag = true;
            break;
        }
        m.insert({cur, 0});
        if (++num > n) {
            num -= n;
            round++;
        }
    }

    if (!flag) {
        answer.push_back(0);
        answer.push_back(0);
    }


    return answer;
}