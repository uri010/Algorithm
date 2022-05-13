#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
queue <pair<int, int>> q;

bool isValid(int x) {
	return x >= 0 && x <= 100000 && visited[x] == false;
}

void BFS(int start, int end) {
	q.push({ 0,start });
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front().second;
		int cnt = q.front().first;
		q.pop();

		if (x == end) {
			cout << cnt;
			return;
		}
		if (isValid(x + 1)) {
			q.push({ cnt + 1,x + 1 });
			visited[x + 1] = true;
		}
		if (isValid(x - 1)) {
			q.push({ cnt + 1, x-1});
			visited[x - 1] = true;
		}
		if (isValid(x * 2)) {
			q.push({ cnt + 1, x * 2 });
			visited[x * 2] = true;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	BFS(n,k);

}