#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
long long n, x;
vector<long long> line;

void input() {
	cin >> k;
	cin >> n;
	for (int i = 0; i < k; i++) {
		cin >> x;
		line.push_back(x);
	}
	sort(line.begin(), line.end());
}

void Solve() { //mid값을 찾는 것도 이분탐색으로 구하기
	long long minLen = 1; // 최소
	long long maxLen = line[k - 1]; // 최대 

	int ans = 0;
	while (maxLen >= minLen) { // 최대 최소 바뀔 때까지 
		long long mid = (minLen + maxLen) / 2; //최대 최소 중앙값
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += line[i] / mid;
			
		}

		if (cnt >= n) {
			ans = mid;
			minLen = mid + 1;
		}
		else {
			maxLen = mid - 1;
		}

	}
	cout << ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	Solve();

}