#include <iostream>
using namespace std;

int map[51][51];
int map_spread[51][51];
int r, c, t;
int top, bottom;

int mv_x[4] = { 1,-1,0,0 };
int mv_y[4] = { 0,0,1,-1 };



void input() {
	cin >> r >> c >> t;
	int tmp = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				tmp = i;
			}
		}
	}
	bottom = tmp;
	top = bottom- 1;
}


bool isValid(int i, int j) {
	if (i < r && i >= 0 && j < c && j >= 0) {
		return true;
	}
	return false;
}

void Spread() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map_spread[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != 0 ) {
				for (int k = 0; k < 4; k++) {
					int x = i + mv_x[k];
					int y = j + mv_y[k];

					if (map[x][y] != -1 && isValid(x, y)) {
						map_spread[x][y] += map[i][j] / 5;
						map_spread[i][j] = map_spread[i][j] - (map[i][j] / 5);
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = map_spread[i][j];
		}
	}
	map[top][0] = -1;
	map[bottom][0] = -1;
}

void WindTop() {
	for (int i = top- 2; i >= 0; i--) {
		map[i + 1][0] = map[i][0];
	}
	for (int i = 1; i < c; i++) {
		map[0][i - 1] = map[0][i];
	}
	for (int i = 1; i <= top; i++) {
		map[i - 1][c-1] = map[i][c-1];
	}
	for (int i = c - 2; i >= 0; i--) {
		map[top][i + 1] = map[top][i];
	}
	map[top][1] = 0;
}

void WindBottom(){
	for (int i = bottom + 2; i < r; i++) {
		map[i - 1][0] = map[i][0];
	}
	for (int i = 1; i < c; i++) {
		map[r - 1][i - 1] = map[r - 1][i];
	}
	for (int i = r - 2; i >= bottom; i--) {
		map[i + 1][c-1] = map[i][c - 1];
	}
	for(int i=c-2; i >= 1; i --){
		map[bottom][i + 1] = map[bottom][i];
	}
	map[bottom][1] = 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	for (int k = 0; k < t; k++) {
		Spread();
		WindTop();
		WindBottom(); 
	
	}
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1) sum += map[i][j];
		}
	
	}
	cout << sum;

}