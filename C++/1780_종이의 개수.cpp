#include <iostream>
using namespace std;

int arr[2188][2188];
int cnt[3];
int n;

void isSame(int x, int y, int size) {
	int data = arr[y][x];
	int flag = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (data != arr[y + i][x + j]) {
				flag = 1;
				break;
			}
		}
	}
	if (flag) {
		int new_size = size / 3;
		if (new_size > 0) {
			for (int a = 0; a < size; a += new_size) {
				for (int b = 0; b < size; b += new_size) {
					isSame(x + b, y + a, new_size);
				}
			}
		}
	}
	else 
		cnt[data + 1]++;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	isSame(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n";
	}


}