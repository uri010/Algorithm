#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int prime = 2;
	while (n != 1) {
		if (n % prime == 0) {
			cout << prime << "\n";
			n = n / prime;
		}
		else {
			prime++;
		}
	}
	
}