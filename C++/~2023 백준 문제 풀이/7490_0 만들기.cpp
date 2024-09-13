//
// Created by 김유리 on 2023/12/12.
//
#include <iostream>
#include <vector>

using namespace std;

int T, N;

bool isZero(string str) {
    int sum = 0;
    int tmp = 0;
    char sign = '+';
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            tmp = tmp * 10 + (str[i] - '0');
            if (i == str.length() - 1) {
                if (sign == '+') {
                    sum += tmp;
                } else if (sign == '-') {
                    sum -= tmp;
                }
            }
        } else if (str[i] == '+' || str[i] == '-') {
            if (sign == '+') {
                sum += tmp;
            } else if (sign == '-') {
                sum -= tmp;
            }
            tmp = 0;
            sign = str[i];
        }
    }
    if (sum == 0) return true;
    return false;
}

void DFS(int num, string str) {
    if (num == N) {
        if (isZero(str)) {
            cout << str << "\n";
        }
        return;
    }

    DFS(num + 1, str + " " + to_string(num + 1));
    DFS(num + 1, str + "+" + to_string(num + 1));
    DFS(num + 1, str + "-" + to_string(num + 1));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N;
        string str = "1";
        DFS(1, str);
        cout << "\n";
    }
}