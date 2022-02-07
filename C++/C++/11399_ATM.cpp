#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> line;
int n;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time; cin >> time;
		line.push({time,i });
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	int eachSum = 0;
	int sum = 0;
	while(!line.empty()) {
		eachSum += line.top().first;
		sum += eachSum;
		line.pop();
	}
	cout << sum << "\n";

}