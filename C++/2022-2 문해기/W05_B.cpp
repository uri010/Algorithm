#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, m, y;
string s, s1, s2;
map<string, int> city;
vector<pair<int, string>> v;
vector<pair<int, int>> edges[50001];
int dp[50001];

void init() {
    city.clear();
    v.clear();
    for (int i = 0; i < 50001; i++) {
        edges[i].clear();
    }
    memset(dp, 0, sizeof(dp));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 0; i < n; i++) {
            cin >> s >> y;
            v.push_back({y, s});
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            city.insert({v[i].second, i});
        }

        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;
            cin >> y;
            int idx1 = city.at(s1);
            int idx2 = city.at(s2);
            if (v[idx1].first < v[idx2].first) {
                edges[idx1].push_back({idx2, y});
            } else if (v[idx1].first > v[idx2].first) {
                edges[idx2].push_back({idx1, y});
            }
        }

        int next;
        int time;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < edges[i].size(); j++) {
                next = edges[i][j].first;
                time = edges[i][j].second;
                dp[next] = max(dp[next], dp[i] + time);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}