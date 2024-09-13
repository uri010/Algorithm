#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int height[101][101];
bool flood[101][101];
int max_rain;

int mv_x[4] = { 1,-1,0,0 };
int mv_y[4] = { 0,0,1,-1 };

void input() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			max_rain = max_rain >= height[i][j] ? max_rain : height[i][j];
		}
	}
}

void DFS(int i, int j, int rain ) {
	flood[i][j] = true;
	
	for (int k = 0; k < 4; k++) {
		int x = i + mv_x[k];
		int y = j + mv_y[k];
		if (x >= 0 && y >= 0 && x < n && y < n) {
			if (height[x][y] > rain && !flood[x][y]) {
				DFS(x, y, rain);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	int max_area = 0;
	
	while (max_rain>0) {
		int cnt = 0;
		memset(flood, false, sizeof(flood));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (height[i][j] > max_rain && !flood[i][j]) {
					DFS(i, j, max_rain);
					cnt++;
				}
			}
		}
		max_area = max(max_area, cnt);
		max_rain--;
	}
	if (max_area == 0)cout << 1;
	else cout << max_area;
}