#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
		
	int ans = 0;
	while (N>=0) {
		if (N % 5 == 0) {
			cout << N / 5 + ans<< "\n";
			return 0;
		}
		N = N - 3;
		ans++;
	}
	cout << -1 << "\n";
}