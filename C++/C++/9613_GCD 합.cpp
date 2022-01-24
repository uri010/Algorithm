#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) return a;
	else
		return GCD(b, a % b);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int arr[101] = { 0, };

		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr[i] = x;
		}

		long long sum = 0;
		for(int i=0; i <n;i++){
			for (int j = i+1; j < n; j++) {
				sum += GCD(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";
	}
}