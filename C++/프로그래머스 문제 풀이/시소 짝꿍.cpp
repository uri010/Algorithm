//
// Created by 김유리 on 2023/09/06.
//
#include <vector>

using namespace std;

long long arr[10000];

long long solution(vector<int> weights) {
    long long answer = 0;

    for (int i = 0; i < weights.size(); i++) {
        arr[weights[i]]++;
    }

    for (int i = 100; i <= 1000; i++) {
        if (arr[i] >= 2) {
            answer += arr[i] * (arr[i] - 1) / 2;
        }
        if ((i * 4 / 2) <= 1000 && arr[i * 4 / 2] > 0) {
            answer += arr[i] * arr[i * 4 / 2];
        }
        if ((i * 3 % 2 == 0) && (i * 3 / 2) <= 1000 && arr[i * 3 / 2] > 0) {
            answer += arr[i] * arr[i * 3 / 2];
        }
        if ((i * 4 % 3 == 0) && (i * 4 / 3) <= 1000 && arr[i * 4 / 3] > 0) {
            answer += arr[i] * arr[i * 4 / 3];
        }
    }

    return answer;
}