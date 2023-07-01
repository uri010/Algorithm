#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int N, M, a, b, t;
vector<vector<pair<int, int>>> edges(1002);
int pred[1002];
bool visited[1002][1002];
int dist[1002];

void Input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }
}

void Init() {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
}

int Escape() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 1}});
    dist[1] = 0;

    while (!pq.empty()) {
        int prev = pq.top().second.first;
        int cur = pq.top().second.second;
        int weight = -pq.top().first;
        pq.pop();

        if (dist[cur] < weight) continue;
        dist[cur] = weight;
        pred[cur] = prev;

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            int next_weight = edges[cur][i].second + weight;

            if (visited[cur][next] || visited[next][cur]) continue;
            if (dist[next] < next_weight) continue;
            dist[next] = next_weight;
            pred[next] = cur;
            pq.push({-next_weight, {cur, next}});
        }
    }
    return dist[N];
}

int CheckPoint() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();

        if (dist[cur] < weight) continue;
        dist[cur] = weight;


        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            int next_weight = edges[cur][i].second + weight;

            if (visited[cur][next] || visited[next][cur]) continue;
            if (dist[next] < next_weight) continue;
            dist[next] = next_weight;

            pq.push({-next_weight, next});
        }
    }
    return dist[N];
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    Input();
    Init();
    Escape();
    int init_dist = dist[N];

    int max_dist = -1;
    int i = N;
    while (i != 1) {
        Init();
        visited[i][pred[i]] = true;
        visited[pred[i]][i] = true;

        int ans = CheckPoint();
        if (max_dist < ans)
            max_dist = ans;

        visited[i][pred[i]] = false;
        visited[pred[i]][i] = false;

        i = pred[i];
    }

    if (max_dist == INF) cout << -1;
    else cout << (max_dist - init_dist);
}
