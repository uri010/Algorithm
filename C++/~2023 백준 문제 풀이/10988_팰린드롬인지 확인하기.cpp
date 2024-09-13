//
// Created by 김유리 on 2024/03/01.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int left = 0;
    int right = str.size() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            cout << 0;
            return 0;
        }
        left++;
        right--;
    }
    cout << 1;
    return 0;
}