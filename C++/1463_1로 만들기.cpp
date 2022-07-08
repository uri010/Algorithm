#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(dp[i / 3],min(dp[i-1], dp[i / 2])) + 1;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cout << dp[n];
}