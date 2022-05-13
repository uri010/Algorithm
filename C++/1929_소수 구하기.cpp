#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (isPrime(i)) {
			cout << i << "\n";
		}
	}


}