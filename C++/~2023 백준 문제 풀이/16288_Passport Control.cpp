#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int n, k;
	cin >> n >> k;

	vector<vector<int>> pass(k);
	vector<int> per;

	for(int i=0; i <n;i ++) {
		int x;
		cin >> x;
		per.push_back(x);
	}

	pass[0].push_back(per[0]);

	for (int i = 1; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < k; j++) {
			if (pass[j].size() == 0) {
				pass[j].push_back(per[i]);
				flag = 1;
				break;
			}if(per[i] > pass[j][pass[j].size() - 1]) {
				pass[j].push_back(per[i]);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
	

}