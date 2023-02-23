#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> jewel;
	int m, v;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel.push({ m,v });
	}
	
	vector<int> bag;

	int c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}
	
	sort(bag.begin(), bag.end());
	
	priority_queue<int> price;

	long long int sum = 0;

	int j = 0; 
	for (int i = 0; i < k; i++) {
		for (; j < n && jewel.top().first <= bag[i]; j++) {
			price.push(jewel.top().second);
			jewel.pop();
		}
		if (!price.empty()) {
			sum += price.top();
			price.pop();
		}
	}
	cout << sum;
}