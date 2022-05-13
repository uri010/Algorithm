#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

bool prime[10000];
bool visited[10000];

void Init() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < 10000; i++) {
		for (int j = 2; i * j < 10000; j++) {
			prime[i * j] = false;
		}
	}
	memset(visited, false, sizeof(visited));
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,0 });
	visited[x] = true;
	
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == y) {
			cout << cnt << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next;
			for (int j = 0; j < 10; j++) {
				string s = to_string(num);
				s[i] = j + '0';
				next = stoi(s);

				if (!prime[next] || visited[next] || next >= 10000 || next < 1000) continue;
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
	cout << "Impossible" << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		Init();
		BFS(x, y);
	}

}