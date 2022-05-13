#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, x, y, d, g;
vector<int> dragon;
bool location[101][101] = { false, };
int mv_x[4] = { 1,0,-1,0 };
int mv_y[4] = { 0,-1,0,1 };

void Dragon() {
	dragon.push_back(0);
	for (int i = 1; i <= 10; i++) {
		int size = dragon.size();
		for (int j = size - 1; j >= 0; j--) {
			dragon.push_back((dragon[j] + 1)%4);
		}
	}
}

void solve() {
	//location¿« xøÕ y¿⁄∏Æ∏¶ πŸ≤„¡·¥ı¥œ ∏¬√„
	location[x][y] = true;
	for (int i = 0; i < pow(2,g); i++) {
		int index = (dragon[i] + d) % 4;
		y = y + mv_y[index];
		x = x + mv_x[index];
		location[x][y] = true;
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i + 1 <= 100 && j + 1 <= 100) {
				if (location[i][j] && location[i + 1][j] && location[i][j + 1] && location[i + 1][j + 1])
					cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Dragon();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		solve();
	}
	cout << count();

}