#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int>& a, pair <int, int>& b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> meet;

	while (n--) {
		int start, end;
		cin >> start >> end;
		meet.push({ start,end });
	}

	int cnt = 1;
	int size = meet.size();
	int tmp = meet.top().second;
	meet.pop();
	for (int i=0 ; i< size-1; i++) {
		
		if (tmp <= meet.top().first) {
			tmp = meet.top().second;
			cnt++;
		}
		meet.pop();
	}
	cout << cnt;
}