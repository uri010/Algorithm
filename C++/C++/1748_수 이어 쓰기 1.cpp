#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long cnt = 0;
	long long n; cin >> n;
	int ten = 10;
	long long num = 1;
	while (n >= ten) {
		cnt += num * 9 * ten / 10;
		num++;
		ten *= 10;
	}
	n = n - ten / 10;
	cnt += num * n;
	string s = to_string(ten/10);
	cnt += s.size();
	cout << cnt;
	
}