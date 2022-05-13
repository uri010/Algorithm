#include <iostream>
using namespace std;

long long divide = 1e9 + 7;
int power(int a, int b) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		long long mul = power(2, b / 2);
		return mul * mul % divide;
	}
	else {
		long long mul = power(2, b / 2);
		long long temp = mul * mul %divide;
		return a * temp % divide;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		long long n; cin >> n;
		if (n == 1) {
			cout << 1 << "\n";
		}else{
			cout << power(2, n - 2) << "\n";
		}
	}
}