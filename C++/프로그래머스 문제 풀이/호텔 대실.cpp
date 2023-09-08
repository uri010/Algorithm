//
// Created by 김유리 on 2023/09/08.
//
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

bool cmp(vector<string> &v1, vector<string> &v2) {
    vector<string> sv1 = split(v1[0], ':');
    vector<string> ev1 = split(v1[1], ':');
    vector<string> sv2 = split(v2[0], ':');
    vector<string> ev2 = split(v2[1], ':');

    int startTime1 = stoi(sv1[0]) * 60 + stoi(sv1[1]);
    int startTime2 = stoi(sv2[0]) * 60 + stoi(sv2[1]);
    int endTime1 = stoi(ev1[0]) * 60 + stoi(ev1[1]);
    int endTime2 = stoi(ev2[0]) * 60 + stoi(ev2[1]);

    if (startTime1 == startTime2) {
        return endTime1 < endTime2;
    } else return startTime1 < startTime2;
}

int solution(vector<vector<string>> book_time) {
    priority_queue<int, vector<int>, greater<int>> q;
    sort(book_time.begin(), book_time.end(), cmp);

    for (int i = 0; i < book_time.size(); i++) {
        vector<string> v1 = split(book_time[i][0], ':');
        vector<string> v2 = split(book_time[i][1], ':');

        int startTime = stoi(v1[0]) * 60 + stoi(v1[1]);
        int endTime = stoi(v2[0]) * 60 + stoi(v2[1]) + 10;

        if (q.empty()) {
            q.push(endTime);
        } else {
            if (q.top() <= startTime) {
                q.pop();
                q.push(endTime);
            } else {
                q.push(endTime);
            }
        }
    }
    return q.size();
}