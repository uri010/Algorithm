//
// Created by 김유리 on 2022/12/04.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int t, n, p, q, x;
vector<int> v;
bool visit[1001];
vector<vector<int>> list;
vector<int> tmp;

void Select(int cnt) {

    if (cnt == n) {
        list.push_back(tmp);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visit[v[i]]) {
            visit[v[i]] = true;
            tmp.push_back(v[i]);
            Select( cnt + 1);
            tmp.pop_back();
            visit[v[i]] = false;
        }
    }
}

long long function( int idx) {
    vector<int> f = list[idx];
    long long ans = 0;
    long long mul = 1;
    for (int i = 0; i < n; i++) {
        ans += f[i] * mul;
        mul *= x;
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        v.clear();
        list.clear();
        tmp.clear();
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        cin >> p >> q >> x;
        Select(0);

        for (int i = 0; i < list.size(); i++) {
            long long ans = function(i)%1013;

            if (p <= ans && ans <= q) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }


}