#include <iostream>
using namespace std;


int gcd(int a, int b) {
	if (a % b == 0) return b;
	else gcd(b, a % b);
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	cout << m - gcd(n, m);

}