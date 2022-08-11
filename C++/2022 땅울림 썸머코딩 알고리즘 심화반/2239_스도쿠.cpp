//
// Created by 김유리 on 2022/08/11.
//
#include <iostream>
#include <vector>

using namespace std;

int map[10][10];
bool width[10][10];
bool length[10][10];
bool square[10][10];
string x;

vector<int> availNumbers(int i, int j) {
    vector<int> tmp;
    int idx = (i / 3) * 3 + j / 3;
    for (int k = 1; k <= 9; k++) {
        if (!width[i][k] && !length[j][k] && !square[idx][k]) {
            tmp.push_back(k);
        }
    }
    return tmp;
}

void printMap() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void solve(int i, int j) {
    if (i == 9) {
        printMap();
        exit(0);
    }

    if (map[i][j] == 0) {
        vector<int> tmp = availNumbers(i, j);
        if (tmp.empty())
            return;
        for (int k = 0; k < tmp.size(); k++) {
            int num = tmp[k];
            int idx = (i / 3) * 3 + j / 3;
            map[i][j] = num;
            width[i][num] = true;
            length[j][num] = true;
            square[idx][num] = true;

            if (j < 8)
                solve(i, j + 1);
            else
                solve(i + 1, 0);

            map[i][j] = 0;
            width[i][num] = false;
            length[j][num] = false;
            square[idx][num] = false;
        }
    } else {
        if (j < 8)
            solve(i, j + 1);
        else
            solve(i + 1, 0);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        cin >> x;
        for (int j = 0; j < 9; j++) {
            map[i][j] = x[j] - '0';
            int num = map[i][j];
            if (num != 0) {
                width[i][num] = true;
                length[j][num] = true;
                int idx = (i / 3) * 3 + j / 3;
                square[idx][num] = true;
            }
        }
    }
    solve(0, 0);
}