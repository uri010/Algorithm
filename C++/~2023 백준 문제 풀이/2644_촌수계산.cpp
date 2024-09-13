#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int start, ended;
int x, y;

vector<vector<int>> family(101);
bool visited[101];

void input() {
	cin >> n;
	cin >> start >> ended;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);
	}
}

queue<pair<int,int>> q;

bool BFS() {
	visited[start] = true;
	q.push({ start, 0 });
	while (!q.empty()) {
		int node = q.front().first;
		int depth = q.front().second;
		if (node == ended) {
			cout << depth;
			return true;
		}
		q.pop();
		for (int i = 0; i < family[node].size(); i++) {
			if (!visited[family[node][i]]) {
				q.push({ family[node][i], depth + 1 });
				visited[family[node][i]] = true;
			}
		}
	}
	return false;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	if (start == ended) cout << 0;
	else {
		if( !BFS())
		cout << -1;
	}
	return 0;
}