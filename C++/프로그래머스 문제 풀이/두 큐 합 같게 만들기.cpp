//
// Created by 김유리 on 2023/11/06.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q1;
queue<int> q2;
long long sum1;
long long sum2;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    for (int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    long long goal = (sum1 + sum2) / 2;

    int cnt = 0;
    while (cnt <= queue1.size() * 2 + 2) {
        cnt++;
        if (sum1 < goal) {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        } else if (sum1 > goal) {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        } else {
            return cnt - 1;
        }
    }
    return -1;
}