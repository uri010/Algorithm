#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<char> result;
int arr[100001] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[index] == i) {
			st.push(i);
			st.pop();
			result.push_back('+');
			result.push_back('-');
			index++;
			while (st.size()!=0 && arr[index] == st.top()) {
				st.pop();
				result.push_back('-');
				index++;
			}
		}
		else {
			st.push(i);
			result.push_back('+');
		}
	}
	if (st.size() == 0) {
		for (int i = 0; i < N * 2; i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << "NO" << "\n";
	}
}