#include <iostream>
#include <math.h>
using namespace std;

bool isPrimeNum(int x) {
	if (x == 1) return false;
	else {
		for (int i = 2; i <=sqrt(x); i++) {
			if (x % i == 0) return false;
		}
	}
	return true;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	int sum = 0;
	int min_prime = 10001;
	for (int i = m; i <= n; i++) {
		if (isPrimeNum(i)) {
			sum += i;
			min_prime = min(min_prime, i);
		}
	}
	if (sum == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << sum << "\n" << min_prime;
	}


}