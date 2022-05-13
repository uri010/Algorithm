#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> v;
	int n;
	cin >> n;
	for(int i=0; i <n;i++) {
		int x, y;
		cin >> x >> y;
		v.push({ x,y });
	}
	for (int i = 0; i < n; i++) {
		cout << v.top().first << " " << v.top().second << "\n";
		v.pop();
	}
	

}