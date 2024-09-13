#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int map[101][101];
bool visit[101][101];
int n;
int mv_x[4] = { 1,-1,0,0 };
int mv_y[4] = { 0,0,1,-1 };

vector<pair<int, int>> v;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
				v.push_back({ i,j });
			}
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

void LandLabel(int x, int y, int l ) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	map[x][y] = l;
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int to_x = x + mv_x[i];
			int to_y = y + mv_y[i];

			if (to_x >= 0 && to_y >= 0 && to_x < n && to_y < n) {
				if (visit[to_x][to_y] ==false && map[to_x][to_y] == -1) {
					visit[to_x][to_y] = true;
					map[to_x][to_y] = l;
					q.push({ to_x, to_y });
				}
			}
		}
	}
}

int BFS(int num){
	int result = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == num)
			{
				visit[i][j] = true;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + mv_x[j];
				int ny = y + mv_y[j];

				if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
					if (map[nx][ny] != 0 && map[nx][ny] != num) return result;
					else if (map[nx][ny] == 0 && visit[nx][ny] == false) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		result++;
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	input();

	int land_label = 1;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (visit[x][y] == false) {
			LandLabel(x, y, land_label);
			land_label++;
		}
	}
	int answer = 1000000;
	for (int i = 1; i < land_label; i++) {
		answer = min(answer, BFS(i));
		memset(visit, false, sizeof(visit));
	}
	cout << answer << "\n";
	
	
}