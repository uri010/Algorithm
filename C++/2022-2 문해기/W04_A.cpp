#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t;
int n, k, v;
int ans;
int weight[501];
int cost[501];
int arr[100001];
priority_queue<int> pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		ans = 0;
		memset(weight, 0, sizeof(weight));
		memset(cost, 0, sizeof(cost));
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			cin >> weight[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < n; i++) {
			int tmp = cost[i] / weight[i];
			arr[tmp] += weight[i];
		}
		for (int i = 100000; i >= 1; i--) {
			int tmp = arr[i];
			if (tmp < k) {
				k -= tmp;
				ans += i * tmp;
			}
			else if (tmp > k) {
				ans += i * k;
				break;
			}
		}
		cout << ans << "\n";
	}
}