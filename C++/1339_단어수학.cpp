#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> str;
	int alpha[26] = {  };

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		string word = str[i];
		int len = word.length();
		int pow = 1;

		for (int j = len - 1; j >= 0; j--) {
			int tmp = word[j] - 'A';
			alpha[tmp] += pow;
			pow *= 10;
		}
	}

	sort(alpha, alpha + 26, greater<>());

	int result = 0;
	int num = 9;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) {
			break;
		}
		result =result + (alpha[i] * num);
		num--;
	}
	cout << result << "\n";

}