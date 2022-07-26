//
// Created by 김유리 on 2022/07/25.
//
#include <iostream>

using namespace std;

int arr[200002];
int jong[500002];
int suk[500002];
int n, h;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> h;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i % 2 == 0) {
            jong[h - arr[i] + 1]++;
        } else {
            suk[arr[i]]++;
        }
    }

    for (int i = 1; i <= h; i++) {
        jong[i + 1] += jong[i];
        suk[h - i] += suk[h - i + 1];
    }

    int min_height = jong[1] + suk[1];
    for (int i = 2; i <= h; i++) {
        min_height = min(min_height, jong[i] + suk[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        if (min_height == jong[i] + suk[i]) cnt++;
    }
    cout << min_height << " " << cnt;
}