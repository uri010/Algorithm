#include <iostream>
#include <queue>
using namespace std;

queue < pair<int, pair<int, int>>> q;
int tomato[1001][1001];
int n, m;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isValid(int x, int y) {
	return x >= 0 && x < m&& y >= 0 && y < n;
}

void BFS() {
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int to_y = y + dy[i];
			int to_x = x + dx[i];
			if (isValid(to_x, to_y) && tomato[to_y][to_x]==0) {
				q.push()
			}
		}
	}
}