//
// Created by 김유리 on 2024/02/07.
//
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <queue>

using namespace std;


map<string, int> m;
map<string, string> par;

void BFS(string name, int amount) {
    queue<string> q;
    q.push(name);

    while (!q.empty()) {
        string cur = q.front();
        if (amount * 0.1 < 1) {
            m[cur] += amount;
            return;
        }
        int tmp = ceil(amount * 0.9);
        m[cur] += tmp;
        q.pop();

        if (par.find(cur) != par.end()) {
            q.push(par[cur]);
            amount = amount - tmp;
        } else {
            return;
        }
    }

}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++) {
        m.insert({enroll[i], 0});
    }
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "-") continue;
        par.insert({enroll[i], referral[i]});
    }

    for (int i = 0; i < seller.size(); i++) {
        BFS(seller[i], amount[i] * 100);
    }

    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(m[enroll[i]]);
    }
    return answer;
}