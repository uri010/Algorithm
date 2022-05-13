#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

char maze[MAX][MAX];

int fire[MAX][MAX];
queue < pair<int, int>> F;

int visit[MAX][MAX];
queue <pair<int, int>> J;

int mv_x[4] = { 1,-1,0,0 };
int mv_y[4] = { 0,0,1,-1 };

int R, C;

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 'J') {
				J.push({ i,j });
				visit[i][j] = 1;
			}

			if (maze[i][j] == 'F') {
				F.push({ i,j });
				fire[i][j] = 1;
			}
		}
	}
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	while (!F.empty()) {
		pair<int, int> cur = F.front();
		F.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.second + mv_x[i];
			int y = cur.first + mv_y[i];
			
			if (x < 0 || x >= C || y < 0 || y >= R) continue;
			if (maze[y][x] == '#' || fire[y][x] != 0) continue;
			fire[y][x] = fire[cur.first][cur.second] + 1;
			F.push({ y,x });
		}
	}
	int flag = 0;
	while (!J.empty()) {
		if (flag == 1) break;
		pair<int, int> cur = J.front();
		J.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.second + mv_x[i];
			int y = cur.first + mv_y[i];
			
			if (x < 0 || x >= C || y < 0 || y >= R)
			{
				flag = 1;
				cout << visit[cur.first][cur.second];
				break;
			}
			if (maze[y][x] == '#' || visit[y][x] != 0) continue;
			if (visit[cur.first][cur.second] + 1 >= fire[y][x] && fire[y][x] >0) continue;

			visit[y][x] = visit[cur.first][cur.second] + 1;
			J.push({ y,x });

		}
	}
	if (flag != 1) cout << "IMPOSSIBLE";


}