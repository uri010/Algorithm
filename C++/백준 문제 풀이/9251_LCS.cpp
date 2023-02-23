#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int LCS[1001][1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str_A, str_B;
	cin >> str_A >> str_B;
	str_A = " " + str_A;
	str_B = " " + str_B;

	int lcs_length = 0;
	for (int i = 0; i <str_A.size(); i++) {
		for (int j = 0; j < str_B.size(); j++) {
			if (i == 0 || j == 0) {
				LCS[i][j] = 0;
			}
			else if (str_A[i] == str_B[j]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
			lcs_length = max(LCS[i][j], lcs_length);
		}
	}
	cout << lcs_length;

}