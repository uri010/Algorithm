//
// Created by 김유리 on 2023/12/11.
//
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool oneCharDiff(string a, string b) {
    int diffCnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) diffCnt++;
    }
    if (diffCnt == 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visited[50] = {false,};
    bool isTarget = false;
    vector<vector<int>> v(words.size());
    vector<int> oneCharDiffList;

    for (int i = 0; i < words.size(); i++) {
        if (oneCharDiff(words[i], begin)) {
            oneCharDiffList.push_back(i);
        }
    }

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target) isTarget = true;
        for (int j = 0; j < words.size(); j++) {
            if (i == j) continue;
            if (oneCharDiff(words[i], words[j])) {
                v[i].push_back(j);
            }
        }
    }
    if (!isTarget) return 0;


    queue<pair<int, int>> q;
    for (int i = 0; i < oneCharDiffList.size(); i++) {
        q.push({oneCharDiffList[i], 1});
        visited[oneCharDiffList[i]] = true;
    }
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (words[cur] == target) {
            answer = max(answer, cnt);
        }

        for (int i = 0; i < v[cur].size(); i++) {
            if (!visited[v[cur][i]]) {
                visited[v[cur][i]] = true;
                q.push({v[cur][i], cnt + 1});
            }
        }
    }
    return answer;
}