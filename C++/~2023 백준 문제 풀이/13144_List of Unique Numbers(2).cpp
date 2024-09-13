//
// Created by 김유리 on 2024/01/15.
//
#include <iostream>

using namespace std;

int N;
int arr[100001];
long ans;
bool visited[100001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long left = 0;
    long right = 0;
    while (right < N) {
        // 중복이 있을 때
        if (visited[arr[right]]) {
            ans += right - left;
            visited[arr[left]] = false;
            left++;
        }
            // 중복이 없을 때
        else {
            visited[arr[right]] = true;
            right++;
        }
    }

    for (long i = left; i < N; i++) {
        ans += right - i;
    }
    cout << ans;

}