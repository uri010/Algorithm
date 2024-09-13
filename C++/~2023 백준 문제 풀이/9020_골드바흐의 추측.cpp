#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int number = 10000; // �迭�� ����
int a[10001]; // �Ҽ��� �����ϴ� �迭 

// �����佺�׳׽��� ü�� �̿��� �Ҽ� �迭 �����
// 2���� �����ؼ� Ư�� ���� ����� �ش��ϴ� ���� ���� ( ���� �� �ڱ��ڽ��� ������ �ʰ�, �̹� ������ ���� �ǳʶ� )
void primeNumberSieve() {
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = 2 * i; j <= number; j += i) {
			a[j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	primeNumberSieve();
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> ans;
		for (int i = 2; i < n; i++) {
			if (a[n - i] + a[i] == n) {
				ans.push_back({ abs(a[n - i] - a[i]), i });
			}
		}
		sort(ans.begin(), ans.end());
		int index = ans[0].second;
		cout << index << " " << a[n - index] << "\n";
	}
}