#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t;
string file1;
string file2;
bool alpha_used[27];
bool alpha[27];


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t; 
	while (t--) {
		cin >> file1 >> file2;
		memset(alpha, false, sizeof(alpha));
		memset(alpha_used, false, sizeof(alpha_used));

		for (int i = 0; i < file1.size(); i++) {
			alpha[file1[i] - 'A'] = true;
		}
		int flag = 1;
		for (int i = 0; i < file2.size(); i++) {
			if (!alpha[file2[i] - 'A']) {
				flag = 0;
				break;
			}
			else {
				alpha_used[file2[i] - 'A'] = true;
			}
		}
		if (flag) {
			int flag2 = 1;
			for (int i = 0; i < 27; i++) {
				if (alpha[i] == true&& alpha_used[i]==false) {
					flag2 = 0;
					break;
				}
			}
			if (flag2)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else cout << "NO\n";
	}

}