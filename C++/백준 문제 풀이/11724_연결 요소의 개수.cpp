#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> map(1001);
bool visited[1001];
int cnt = 0;

void input() {
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
}

void DFS(int x) {
	visited[x] = true;
	
	for (int i = 0; i < map[x].size(); i++) {
		if (!visited[map[x][i]]) {
			DFS(map[x][i]);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	for (int i = 1; i <=n; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;
}