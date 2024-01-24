//
// Created by 김유리 on 2024/01/24.
//
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    while (n > 0) {
        int num = pq.top();
        pq.pop();
        if (num == 0) return 0;

        num--;
        pq.push(num);
        n--;
    }
    while (!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}