#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

void ArrayPrint(vector<int> &arr) {
	cout << "[";
	for (int i = 0; i < arr.size()-1; i++) {
		cout << arr[i] << ",";
	}
	cout << arr[arr.size() - 1] << "]" << "\n";
}

void ArrayPrintReverse(vector<int>& arr) {
	cout << "[";
	for (int i = arr.size()-1; i >0 ; i--) {
		cout << arr[i] << ",";
	}
	cout << arr[0] << "]" << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t, n, x;
	string p;

	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;
		getchar();
		getchar();
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr.push_back(x);
			getchar();
		}
		int cnt = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				cnt++;
			}
			else if (p[i] == 'D') {
				if (arr.size() == 0) {
					cnt = -1;
					break;
				}
				else if (cnt % 2 == 0) {
					arr.erase(arr.begin());
				}
				else if (cnt % 2 == 1) {
					if (arr.size() != 1) {
						arr.erase(arr.end() - 1);
					}
					else if (arr.size() == 1) {
						arr.erase(arr.begin());
					}

				}
			}
		}
		if (cnt == -1||arr.size() == 0 ) {
			cout << "error" << "\n";
		}
		else if (cnt % 2 == 0) {
			ArrayPrint(arr);
		}
		else if (cnt % 2 == 1) {
			ArrayPrintReverse(arr);
		}
	}

}