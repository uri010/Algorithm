//
// Created by 김유리 on 2024/03/01.
//
#include <iostream>
#include <algorithm>

using namespace std;

int t[101];
int A, B, C;
int enter, out;
int maxOut;
int cost;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> A >> B >> C;
    for (int i = 0; i < 3; i++) {
        cin >> enter >> out;
        maxOut = max(out, maxOut);
        for (int j = enter; j < out; j++) {
            t[j]++;
        }
    }

    for (int i = 1; i < maxOut; i++) {
        switch (t[i]) {
            case 1:
                cost += A;
                break;
            case 2:
                cost += B * 2;
                break;
            case 3:
                cost += C * 3;
                break;
        }
    }
    cout << cost;
}