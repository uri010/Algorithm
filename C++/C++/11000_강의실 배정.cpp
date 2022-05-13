#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> classes;
	priority_queue <int, vector< int>, greater<int>> lec;

	while (n--) {
		int s, t;
		cin >> s >> t;
		classes.push_back({ s,t });
	}
	sort(classes.begin(), classes.end());


	for (int i = 0; i < classes.size(); i++) {
		int start = classes[i].first;
		int end = classes[i].second;
		if (lec.empty()) {
			lec.push(end);
		}
		else {
			if (start >= lec.top()) {
				lec.pop();
				lec.push(end);
			}
			else {
				lec.push(end);
			}
		}
	}
	cout << lec.size();
	
}