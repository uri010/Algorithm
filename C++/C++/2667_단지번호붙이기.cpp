#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N;
queue <pair <int,int>> q;
bool visited[25][25];
vector<int> cnt;

int mv_x[4] = { 1,-1, 0, 0 };
int mv_y[4] = { 0,0,1,-1 };

bool Range(int x, int y) {
	return x < N&& y < N&& x >= 0 && y >= 0;
}

int BFS(int x, int y,int a[][26]) {
	int cnt = 0;
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int to_x = x + mv_x[i];
			int to_y = y + mv_y[i];
			if (Range(to_x, to_y) && !visited[to_x][to_y] && a[to_x][to_y] == 1) {
				q.push(make_pair(to_x, to_y));
				visited[to_x][to_y] = true;
			}
		}
	}
	return cnt;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	int a[26][26] = { 0, };
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j] = s[j] - '0';
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j]==1 && !visited[i][j]) {
				q.push(make_pair(i,j));
				cnt.push_back(BFS(i, j,a));
			}
		}
	}
	sort(cnt.begin(), cnt.end());

	cout << cnt.size() << "\n";
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << "\n";
	}

}