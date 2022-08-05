//
// Created by 김유리 on 2022/08/05.
//
#include <iostream>
#include <queue>
#include <map>
#include <cstring>

#define INF 100000000
using namespace std;

int n, r, m, e;
double d;
string a, b, c;
string s;
map<string, int> city;
map<string, int> type;
vector<int> route;
double dist[102][102];
vector<pair<int, double>> cost[102][102];

void init() {
    type.insert({"Subway", 1});
    type.insert({"Bus", 2});
    type.insert({"Taxi", 3});
    type.insert({"Airplane", 4});
    type.insert({"KTX", 5});
    type.insert({"S-Train", 6});
    type.insert({"V-Train", 7});
    type.insert({"ITX-Saemaeul", 8});
    type.insert({"ITX-Cheongchun", 9});
    type.insert({"Mugunghwa", 10});
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    init();
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (city.count(s) != 0) continue;
        city.insert({s, i});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (city.count(s) != 0)
            route.push_back(city.at(s));
    }

    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c >> d;
        int trans = type.at(a);
        int c1 = city.at(b);
        int c2 = city.at(c);
        cost[c1][c2].push_back({trans, d});
        cost[c2][c1].push_back({trans, d});
        if (dist[c1][c2] > d) {
            dist[c1][c2] = d;
        }
        if (dist[c2][c1] > d) {
            dist[c2][c1] = d;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    double normal_cost = 0;
    for (int i = 0; i < route.size() - 1; i++) {
        normal_cost += dist[route[i]][route[i + 1]];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < cost[i][j].size(); k++) {
                int trans = cost[i][j][k].first;
                if (trans == 8 || trans == 9 || trans == 10) {
                    cost[i][j][k].second = 0;
                } else if (trans == 6 || trans == 7) {
                    cost[i][j][k].second /= 2;
                }
                if (dist[i][j] > cost[i][j][k].second) {
                    dist[i][j] = cost[i][j][k].second;
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    double naeillo = r;
    for (int i = 0; i < route.size() - 1; i++) {
        naeillo += dist[route[i]][route[i + 1]];
    }

    if (naeillo < normal_cost) cout << "Yes";
    else cout << "No";

}