//
// Created by 김유리 on 2024/01/11.
//
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int now[100001];
int copyNow[100001];
int result[100001];
int ans = -1;

void push(int bulb[], int switchNum) {
    for (int i = switchNum - 1; i <= switchNum + 1; i++) {
        if (i >= 0 && i < N)
            bulb[i] = 1 - bulb[i];
    }
}

bool solve(int bulb[], int targetBulb[], int &result) {
    int tmp = 0;
    for (int i = 1; i < N; i++) {
        if (bulb[i - 1] != targetBulb[i - 1]) {
            push(bulb, i);
            tmp++;
        }
    }
    result = tmp;

    for (int i = 0; i < N; i++) {
        if (bulb[i] != targetBulb[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    string first, second;
    cin >> first;
    cin >> second;
    for (int i = 0; i < N; i++) {
        now[i] = first[i] - '0';
        copyNow[i] = (int) first[i] - '0';
        result[i] = (int) second[i] - '0';
    }

    int nowAns = 0;
    //0번 스위치 안 눌렀을 때
    if (solve(now, result, nowAns)) {
        if (ans == -1) ans = nowAns;
        else ans = min(ans, nowAns);
    }

    //0번 스위치 눌렀을 때
    push(copyNow, 0);
    nowAns = 1;
    if (solve(copyNow, result, nowAns)) {
        nowAns++;
        if (ans == -1) ans = nowAns;
        else ans = min(ans, nowAns);
    }
    cout << ans;
}
