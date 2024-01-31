//
// Created by 김유리 on 2024/01/31.
//
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int aIdx = 0;
    int bIdx = 0;

    while (bIdx < B.size()) {
        if (A[aIdx] < B[bIdx]) {
            answer++;
            aIdx++;
            bIdx++;
        } else {
            bIdx++;
        }
    }

    return answer;
}