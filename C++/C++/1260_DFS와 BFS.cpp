#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


bool visited[1001];
queue <int> q;


void DFS(int v, vector<vector<int>> a) {
	visited[v] = true;
	cout << v << " ";

	for (int i = 0; i < a[v].size(); i++) {
		if (!visited[a[v][i]]) {
			DFS(a[v][i], a);
		}
	}
}

void BFS(vector<vector<int>> a) {
	
	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			if (!visited[a[node][i]]) {
				q.push(a[node][i]);
				visited[a[node][i]] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;

	vector<vector <int>> a(N + 1);
	while (M--) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i < N+1; i++) {
		sort(a[i].begin(), a[i].end());
	}
	DFS(V,a);

	cout << "\n";
	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}

	q.push(V);
	visited[V] = true;
	BFS(a);



}