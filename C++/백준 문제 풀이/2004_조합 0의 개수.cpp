#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;

long long div_5(long long x) {
	long long ans = 0;
	for (long long i = 5; i <= x; i = i * 5) {
		ans += x / i;
	}
	return ans;
}

long long div_2(long long x) {
	long long ans = 0;
	for (long long i = 2; i <= x; i = i * 2) {
		ans += x / i;
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	cout << min(div_5(n) - (div_5(m) + div_5(n - m)), div_2(n) - (div_2(m) + div_2(n - m)));

}