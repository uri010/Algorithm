#include <iostream>
#include <queue>
using namespace std;

int map[17][17];
int n;

void input() {
	cin >> n;
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

int cnt;

void BFS() {
	queue <pair<int,pair<int, int>>> q;
	q.push({ 1,{1,2} });


	while (!q.empty()) {
		int pipe = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		if (x == n && y == n) {
			cnt++;
		}

		if (pipe == 1) {
			if (y + 1 >= 0 && y + 1 <= n && map[x][y + 1] == 0) {
				q.push({ 1,{x,y + 1} });
			}
			if (x + 1 <= n && y + 1 <= n && map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x + 1][y + 1] == 0) {
				q.push({ 3, {x + 1, y + 1} });
			}

		}
		else if (pipe == 2) {
			if (x + 1 <= n && map[x + 1][y] == 0) {
				q.push({ 2, {x + 1, y} });
			}
			if (x + 1 <= n && y + 1 <= n && map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x + 1][y + 1] == 0) {
				q.push({ 3, {x + 1, y + 1} });
			}
		}
		else if (pipe == 3) {
			if (y + 1 >= 0 && y + 1 <= n && map[x][y + 1] == 0) {
				q.push({ 1,{x,y + 1} });
			}
			if (x + 1 <= n && map[x + 1][y] == 0) {
				q.push({ 2, {x + 1, y} });
			}
			if (x + 1 <= n && y + 1 <= n && map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x + 1][y + 1] == 0) {
				q.push({ 3, {x + 1, y + 1} });
			}
		}

	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	BFS();
	cout << cnt << "\n";
}
