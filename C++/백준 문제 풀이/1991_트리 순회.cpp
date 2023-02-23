#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> node(26);

void pre(char cur) {
	if (cur == '.') return;
	cout << cur;
	pre(node[cur - 'A'].first);
	pre(node[cur - 'A'].second);
}

void in(char cur) {
	if (cur == '.') return;
	in(node[cur - 'A'].first);
	cout << cur;
	in(node[cur - 'A'].second);
}

void post(char cur) {
	if (cur == '.')return;
	post(node[cur - 'A'].first);
	post(node[cur - 'A'].second);
	cout << cur;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		node[root - 'A'] = { left,right };
	}
	pre('A');
	cout << "\n";
	in('A');
	cout << "\n";
	post('A');

	
}