//
// Created by 김유리 on 2024/01/20.
//
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }

    while (n > 0) {
        int num = s / n;
        answer.push_back(num);
        s -= num;
        n--;

    }
    return answer;
}