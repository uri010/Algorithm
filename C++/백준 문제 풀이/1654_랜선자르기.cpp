#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
long long n, x;
vector<long long> line;

void input() {
	cin >> k;
	cin >> n;
	for (int i = 0; i < k; i++) {
		cin >> x;
		line.push_back(x);
	}
	sort(line.begin(), line.end());
}

void Solve() { //mid���� ã�� �͵� �̺�Ž������ ���ϱ�
	long long minLen = 1; // �ּ�
	long long maxLen = line[k - 1]; // �ִ� 

	int ans = 0;
	while (maxLen >= minLen) { // �ִ� �ּ� �ٲ� ������ 
		long long mid = (minLen + maxLen) / 2; //�ִ� �ּ� �߾Ӱ�
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += line[i] / mid;
			
		}

		if (cnt >= n) {
			ans = mid;
			minLen = mid + 1;
		}
		else {
			maxLen = mid - 1;
		}

	}
	cout << ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	Solve();

}