#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[201][201];
bool visited[201][201][31];
queue <pair <pair<int, int>, pair<int,int>>> q;
int k, w, h;
int mv_x[4] = { 1,-1, 0, 0 };
int mv_y[4] = { 0, 0, 1, -1 };
int hmv_x[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hmv_y[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void Input() {
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
}

void Solve() {
	queue <pair <pair<int, int>, pair<int, int>>> q;

	q.push({{ 0,0 }, { 0,0 }});
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int ability = q.front().second.second;
		q.pop();

		if (x == h - 1 && y == w - 1) {
			cout << cnt << "\n";
			return;
		}
		//�ɷ� ��� Ƚ���� �־��� �ɷ� ��� Ƚ��(k)���� �۴ٸ� �� �ɷ� ���!
		if (ability < k) {
			for (int i = 0; i < 8; i++) {
				int to_x = x + hmv_x[i];
				int to_y = y + hmv_y[i];

				if (to_x >= 0 && to_y >= 0 && to_x < h && to_y < w) { //���� üũ
					if (map[to_x][to_y] == 0 && visited[to_x][to_y][ability +1] == false) { //��ֹ��� ���� �ش� ��ǥ�� �ɷ�+1�� �湮�� ���� ���� ��
						visited[to_x][to_y][ability+1] = true; 
						q.push({ {to_x, to_y}, {cnt + 1, ability + 1} });

					}
				}
			}
		}

		//�׳� �̵� 4��
		for (int i = 0; i < 4; i++) {
			int to_x = x + mv_x[i];
			int to_y = y + mv_y[i];

			if (to_x >= 0 && to_y >= 0 && to_x < h && to_y < w) { //���� üũ
				if (map[to_x][to_y] == 0 && visited[to_x][to_y][ability] == false) { //��ֹ��� ���� �ش� ��ǥ�� �湮�� ���� ���� ��
					visited[to_x][to_y][ability] = true;
					q.push({ {to_x, to_y}, {cnt + 1, ability} });
				}
			}
		}
	}
	cout << -1 << "\n"; //���� ���ϸ� -1 ���
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Input();
	Solve();
}