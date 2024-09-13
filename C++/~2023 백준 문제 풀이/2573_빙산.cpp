#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int ice[301][301];
int next_ice[301][301];
bool visited[301][301];
queue<pair<int, int>> q;
int n, m;

int mv_x[4] = { 1,-1,0,0 };
int mv_y[4] = { 0,0,1,-1 };

bool isValid(int x, int y) {
	return x >= 0 && x < m&& y >= 0 && y < n;
}

void BFS(int y, int x) {
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int to_x = x + mv_x[i];
			int to_y = y + mv_y[i];
			if (isValid(to_x, to_y) && !visited[to_y][to_x] && ice[to_y][to_x] != 0 ) {
				q.push({ to_x, to_y });
				visited[to_y][to_x] = true;
			}
		}
	}

}

int melt(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int to_x = x + mv_x[i];
		int to_y = y + mv_y[i];

		if (isValid(to_x, to_y) && ice[to_y][to_x] == 0) cnt++;
	}
	return cnt;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	int year = 0;
	while (true) {
		int land = 0;
		memset(visited, false, sizeof(visited));
		memset(next_ice, 0, sizeof(next_ice));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0 && visited[i][j] == false) {
					BFS(i, j);
					land++;
				}
			}
		}

		if (land >= 2) {
			cout << year << "\n";
			break;
		}
		else if(land == 0){
			cout << 0 << "\n";
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0) {
					next_ice[i][j] = ice[i][j] - melt(i, j);
					if (next_ice[i][j] < 0) next_ice[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ice[i][j] = next_ice[i][j];
			}
		}

		year++;
	}
}