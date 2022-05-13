#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int x, y;
int cheeze[101][101];
bool visited[101][101];

int mv_x[4] = { 1,-1,0,0 };
int mv_y[4] = { 0,0,1,-1 };

int ans, melt;

void input() {
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> cheeze[i][j];
		}
	}
}

bool BFS() {
	visited[0][0] = true;
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	melt++;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int to_a = a + mv_x[i];
			int to_b = b + mv_y[i];

			if (to_a >= 0 && to_a < x && to_b >= 0 && to_b < y && !visited[to_a][to_b])
			{
				if (cheeze[to_a][to_b] == 0) {
					q.push({ to_a, to_b });
				}
				else {
					cheeze[to_a][to_b] = 0;
					cnt++;
				}
				visited[to_a][to_b] = true;
			}
		}
	}

	if (cnt == 0) {
		melt--;
		cout << melt << "\n";
		cout << ans;
		return true;
	}
	else {
		ans = cnt;
		return false;
	}
	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	while (true) {
		if (BFS()) {
			break;
		}
		memset(visited, false, sizeof(visited));
	}
	

}