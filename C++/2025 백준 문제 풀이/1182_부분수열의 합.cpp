#include <iostream>

using namespace std;

int N, S, cnt;
int arr[21];

void func(int idx, int total) {
    if (idx == N) {
        if (total == S) cnt++;
        return;
    }

    func(idx + 1, total);
    func(idx + 1, total + arr[idx]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    func(0, 0);

    if (S == 0) cnt--;
    cout << cnt;
}