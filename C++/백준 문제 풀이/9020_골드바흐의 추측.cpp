#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int number = 10000; // 배열의 범위
int a[10001]; // 소수만 저장하는 배열 

// 에라토스테네스의 체를 이용한 소수 배열 만들기
// 2부터 시작해서 특정 수의 배수에 해당하는 수를 지움 ( 지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뜀 )
void primeNumberSieve() {
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = 2 * i; j <= number; j += i) {
			a[j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	primeNumberSieve();
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> ans;
		for (int i = 2; i < n; i++) {
			if (a[n - i] + a[i] == n) {
				ans.push_back({ abs(a[n - i] - a[i]), i });
			}
		}
		sort(ans.begin(), ans.end());
		int index = ans[0].second;
		cout << index << " " << a[n - index] << "\n";
	}
}