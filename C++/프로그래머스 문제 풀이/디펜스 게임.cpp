//
// Created by 김유리 on 2023/11/08.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    if (enemy.size() == k) return enemy.size();
    for (int i = 0; i < enemy.size(); i++) {
        if (n < enemy[i] && k == 0) break;
        pq.push(enemy[i]);
        n -= enemy[i];
        answer++;

        while (n < 0 && !pq.empty()) {
            if (k == 0) {
                answer--;
                break;
            }
            n += pq.top();
            pq.pop();
            k--;
        }
    }
    return answer;
}