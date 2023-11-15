//
// Created by 김유리 on 2023/11/15.
//
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    // t는 대기실 하나를 의미
    for (int t = 0; t < places.size(); t++) {
        //i와 j는 한 대기실의 좌표를 의미
        bool flag = true;
        vector<pair<int, int>> people;
        for (int i = 0; i < places[t].size(); i++) {
            for (int j = 0; j < places[t][i].size(); j++) {
                if (places[t][i][j] == 'P')
                    people.push_back({i, j});
            }
        }
        for (int i = 0; i < people.size(); i++) {
            int cur_i = people[i].first;
            int cur_j = people[i].second;
            for (int j = i + 1; j < people.size(); j++) {
                int next_i = people[j].first;
                int next_j = people[j].second;

                int man = abs(cur_i - next_i) + abs(cur_j - next_j);
                if (man > 2) continue;
                else if (man == 2) {
                    if (abs(cur_i - next_i) == 2 && places[t][cur_i + 1][cur_j] == 'X') continue;
                    if (abs(cur_j - next_j) == 2 && places[t][cur_i][cur_j + 1] == 'X') continue;
                    if (abs(cur_i - next_i) == 1) {
                        if (cur_j < next_j && places[t][cur_i + 1][cur_j] == 'X'
                            && places[t][cur_i][cur_j + 1] == 'X')
                            continue;
                        if (cur_j > next_j && places[t][cur_i][cur_j - 1] == 'X'
                            && places[t][cur_i + 1][cur_j] == 'X')
                            continue;
                    }
                    flag = false;
                    break;
                } else if (man == 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!flag) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}