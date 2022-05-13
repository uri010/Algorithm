#include <iostream>
#include <string.h>
#include <vector>
#define MAX 4000001
using namespace std;

bool prime[MAX];
vector<int> prime_num;

void Init(int n) {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= n; i++) {
		for (int j = 2; i * j <= n; j++) {
			prime[i * j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (prime[i]) prime_num.push_back(i);
	}
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	Init(n);

	int cnt = 0;
	for (int i = 0; i < prime_num.size(); i++) {
		if (prime_num[i] > n) break;
		int sum = 0;
		for (int j = i; j < prime_num.size(); j++) {
			sum += prime_num[j];
			if (sum == n) cnt++;
			else if (sum > n) break;
		}
	}
	cout << cnt;


}