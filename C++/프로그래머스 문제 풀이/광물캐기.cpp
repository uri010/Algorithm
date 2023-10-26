//
// Created by 김유리 on 2023/10/26.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    int totalPicks = 0;
    for (int i = 0; i < picks.size(); i++) {
        totalPicks += picks[i];
    }
    int size = minerals.size();
    if (minerals.size() > totalPicks * 5)
        size = totalPicks * 5;

    int diaCnt = 0;
    int ironCnt = 0;
    int stoneCnt = 0;

    for (int i = 0; i < size; i++) {
        if (minerals[i] == "diamond") {
            diaCnt += 1;
            ironCnt += 5;
            stoneCnt += 25;
        } else if (minerals[i] == "iron") {
            diaCnt += 1;
            ironCnt += 1;
            stoneCnt += 5;
        } else {
            diaCnt += 1;
            ironCnt += 1;
            stoneCnt += 1;
        }

        if (i % 5 == 4 || i == size - 1) {
            pq.push({stoneCnt, {ironCnt, diaCnt}});
            stoneCnt = 0;
            ironCnt = 0;
            diaCnt = 0;
        }
    }

    while (!pq.empty()) {
        stoneCnt = pq.top().first;
        ironCnt = pq.top().second.first;
        diaCnt = pq.top().second.second;
        pq.pop();

        if (picks[0] > 0) {
            picks[0]--;
            answer += diaCnt;
        } else if (picks[1] > 0) {
            picks[1]--;
            answer += ironCnt;
        } else if (picks[2] > 0) {
            picks[2]--;
            answer += stoneCnt;
        } else {
            break;
        }
    }
    return answer;
}