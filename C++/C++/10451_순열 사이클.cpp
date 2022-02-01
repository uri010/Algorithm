#include <iostream>
using namespace std;

int arr[1001];
bool visited[1001];

void Visit(int index) {
	visited[index] = true;
	if (visited[arr[index]]) {
		return;
	}
	Visit(arr[index]);
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			arr[i] = x;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				Visit(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
		init(n);
	}
}