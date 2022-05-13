#include <iostream>
using namespace std;

int in[100001];
int post[100001];
int index[100001];

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) return;

	int root = index[post[postEnd]];
	int leftArea = root - inStart; // 5
	int rightArea = inEnd - root; // 3

	cout << in[root] << " ";

	preorder(inStart, inStart+leftArea-1, postStart, postStart+ leftArea - 1);
	preorder(inEnd - rightArea+1, inEnd, postEnd-rightArea, postEnd - 1);
	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		index[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	
	preorder(0, n - 1, 0, n - 1);

}