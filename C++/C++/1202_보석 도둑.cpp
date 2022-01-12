#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int>& a, pair <int, int>& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> jewel;
	vector<int> bag;

	int n, k, m, v, c;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel.push({ m,v });
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}

}