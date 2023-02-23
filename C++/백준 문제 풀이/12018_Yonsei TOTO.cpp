#include <iostream>
#include <vector>
#include <queue>
using namespace std;



struct cmp {
	bool operator()(int n1, int n2) {
		if (n1 >= n2) {
			return true;
		}
		return false;
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m; int p, l;
	cin >> n >> m;
	
	priority_queue<int, vector<int>, greater<int>> mile;

	while (n--) {
		priority_queue<int> attend;
		cin >> p >> l;
		int x;
		for(int i=0; i <p; i++){
			cin >> x;
			attend.push(x);
		}
		if (p < l) {
			mile.push(1);
		}
		else {
			for (int i = 0; i < l - 1; i++) {
				attend.pop();
			}
			mile.push(attend.top());
		}
	}

	int ans = 0;
	int cnt = 0;
	int size = mile.size();
	for (int i = 0; i < size; i++) {
		if (ans + mile.top() > m) {
			break;
		}
		cnt++;
		ans += mile.top();
		mile.pop();
	}
	cout << cnt;


}