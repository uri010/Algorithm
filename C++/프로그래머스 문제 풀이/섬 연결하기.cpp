//
// Created by 김유리 on 2024/02/25.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int id[101];

int getParent(int v) {
    if (id[v] == v) return v;
    return id[v] = getParent(id[v]);
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        id[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); i++) {
        int v = getParent(costs[i][0]);
        int w = getParent(costs[i][1]);
        int cost = costs[i][2];

        if (v != w) {
            answer += cost;
            id[w] = v;
        }
    }
    return answer;
}