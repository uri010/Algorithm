//
// Created by 김유리 on 2024/03/06.
//
#include <iostream>

using namespace std;

int N, M, J;
int arr[20];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M >> J;
    for (int i = 0; i < J; i++) {
        cin >> arr[i];
    }

    int left = 1;
    int right = M;

    int distance = 0;
    for (int i = 0; i < J; i++) {
        if (arr[i] < left) {
            int diff = abs(left - arr[i]);
            distance += diff;
            left -= diff;
            right -= diff;
        } else if (arr[i] > right) {
            int diff = arr[i] - right;
            distance += diff;
            left += diff;
            right += diff;
        } else {
            continue;
        }
    }
    cout << distance;
}