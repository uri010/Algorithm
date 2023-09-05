//
// Created by 김유리 on 2023/09/05.
//
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());

    for (int i = score.size() - 1; i >= 0; i -= m) {
        if (i < m - 1) break;
        answer += (score[i - m + 1] * m);
    }

    return answer;
}