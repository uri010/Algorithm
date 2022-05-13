#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> node[10001];
bool visited[10001];
int n;
int max_len = 0;
int end_point = 0;

void input() {
	cin >> n;
	int x, y, z;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y >> z;
		node[x].push_back({ y, z });
		node[y].push_back({ x, z });
	}
}

void DFS(int x, int len) {
	if (visited[x]) return;
	visited[x] = true;

	if (max_len < len) {
		max_len = len;
		end_point = x;
	}
	for (int i = 0; i < node[x].size(); i++) {
		if(!visited[node[x][i].first]) 
			DFS(node[x][i].first, len + node[x][i].second);
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	max_len = 0;

	DFS(end_point, 0);
	cout << max_len;
}