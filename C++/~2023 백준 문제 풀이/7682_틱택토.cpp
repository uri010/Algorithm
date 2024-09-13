//
// Created by 김유리 on 2024/01/23.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isX;
bool isO;

void checkThree(string str) {
    //세로
    for (int i = 0; i < 3; i++) {
        if (str[i] == str[i + 3] && str[i] == str[i + 6] && str[i] != '.') {
            if (str[i] == 'X') isX = true;
            else isO = true;
        }
    }

    //가로
    for (int i = 0; i < 7; i += 3) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] != '.') {
            if (str[i] == 'X') isX = true;
            else isO = true;
        }
    }

    //대각선
    if (str[0] == str[4] && str[0] == str[8] && str[0] != '.') {
        if (str[0] == 'X') isX = true;
        else isO = true;
    }
    if (str[2] == str[4] && str[2] == str[6] && str[2] != '.') {
        if (str[2] == 'X') isX = true;
        else isO = true;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    while (cin >> str) {
        if (str == "end")
            return 0;

        //8가지 방향으로 3칸 확인
        isX = false;
        isO = false;
        checkThree(str);
        int xCnt = 0;
        int oCnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'X') xCnt++;
            else if (str[i] == 'O') oCnt++;
        }

        if (isX && !isO && xCnt == oCnt + 1) {
            cout << "valid\n";
        } else if (!isX && isO && xCnt == oCnt) {
            cout << "valid\n";
        } else if (!isX && !isO && xCnt == 5 && oCnt == 4) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }
}