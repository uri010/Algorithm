#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int new_stick = 0;
	int depth = 0;
	int ans = 0;
	str = " " + str;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '(') {
			depth++;
		}
		else {
			depth--;
		}

		if (str[i - 1] == '(' && str[i] == '(') {
			new_stick++;
		}

		if (str[i - 1] == '(' && str[i] == ')') {
			ans += new_stick + depth;
			new_stick = 0;
		}
	}
	cout << ans;
}