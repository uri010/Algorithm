#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

void ArrayPrint(deque<int> &arr) {
	cout << "[";
	if (arr.size() != 0) {
		for (int i = 0; i < arr.size() - 1; i++) {
			cout << arr[i] << ",";
		}
		cout << arr[arr.size() - 1];
	}
	cout << "]" << "\n";
}

void ArrayPrintReverse(deque<int>& arr) {
	cout << "[";
	if (arr.size() != 0) {
		for (int i = arr.size() - 1; i > 0; i--) {
			cout << arr[i] << ",";
		}
		cout << arr[0];
	}
	cout<< "]" << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t, n;
	string p, x;

	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;
		cin >> x;
		deque<int> arr;
		string tmp;
		if (x.size() != 2) {
			for (int i = 1; i < x.size(); i++) {
				if (i == x.size() - 1) {
					arr.push_back(stoi(tmp));
				}
				else if (x[i] != ',') {
					tmp += x[i];
				}
				else {
					arr.push_back(stoi(tmp));
					tmp = "";
				}
			}
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
					arr.pop_front();
				}
				else if (cnt % 2 == 1) {
					arr.pop_back();
				}
			}
		}
		if (cnt == -1 ) {
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