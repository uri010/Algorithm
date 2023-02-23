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

	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		int x;
		cin >> x;
		if (isPrime(x)) cnt++;
	}
	cout << cnt;
}