#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t, n, m, u, v;
vector<vector<int>> edge(100001);
bool visited[100001];
bool infected[100001];


int DFS(int prev, int cur) {
    int cnt = 0;
    if (infected[cur]) cnt++;
    for (int i = 0; i < edge[cur].size(); i++) {
        int next = edge[cur][i];
        if (!visited[next]) {
            visited[next] = true;
            int ret = DFS(cur, next);
            if (ret == m)
                return m;
            else
                cnt += ret;
        }
    }
    if (cnt == m) {
        if (cur == 1)
            cout << "-1\n";
        else if (cur < prev)
            cout << cur << " " << prev << "\n";
        else
            cout << prev << " " << cur << "\n";
    }
    return cnt;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i=0; i <n-1; i ++){
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int x;
        for(int i=0; i <m; i++){
            cin >> x;
            infected[x] = true;
        }

        visited[1] = true;
        DFS(0, 1);

        for (int i = 0; i < edge.size(); i++) {
            edge[i].clear();
        }
        memset(visited, false, sizeof(visited));
        memset(infected, false, sizeof(infected));
    }

}
/*
 * 2 7 2 1 2 1 5 1 7 3 5 5 6 2 4 3 6 4 3 1 2 1 3 1 4 2 3 4
 */