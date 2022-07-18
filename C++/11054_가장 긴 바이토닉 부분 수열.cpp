//
// Created by 김유리 on 2022/07/18.
//
#include <iostream>
#include <cmath>

using namespace std;

int dp_in[1001];
int dp_de[1001];
int arr[1001];
int n;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp_in[i] = 1;
        dp_de[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp_in[i] = max(dp_in[i], dp_in[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (arr[j] < arr[i]) {
                dp_de[i] = max(dp_de[i], dp_de[j] + 1);
            }
        }
    }

    int result = dp_in[0] + dp_de[0] - 1;
    for (int i = 1; i < n; i++) {
        int tmp = dp_in[i] + dp_de[i] - 1;
        if (result < tmp) result = tmp;
    }
    cout << result;
}