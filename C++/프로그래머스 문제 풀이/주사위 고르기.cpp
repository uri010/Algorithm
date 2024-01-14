//
// Created by 김유리 on 2024/01/14.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int comb[5];
int remain[5];
int remainSize = 0;
int maxWin = 0;
vector<int> maxWinDices;
bool visited[11];

void diceSum(int n, vector<vector<int>> dice) {
    vector<int> v1;
    vector<int> v2;
    vector<int> tmp;

    for (int i = 0; i < 6; i++) {
        v1.push_back(dice[comb[0] - 1][i]);
    }
    for (int i = 1; i < n / 2; i++) {
        for (int j = 0; j < v1.size(); j++) {
            for (int k = 0; k < 6; k++) {
                tmp.push_back(v1[j] + dice[comb[i] - 1][k]);
            }
        }
        v1.clear();
        v1 = tmp;
        tmp.clear();
    }

    for (int i = 0; i < 6; i++) {
        v2.push_back(dice[remain[0] - 1][i]);
    }
    for (int i = 1; i < n / 2; i++) {
        for (int j = 0; j < v2.size(); j++) {
            for (int k = 0; k < 6; k++) {
                tmp.push_back(v2[j] + dice[remain[i] - 1][k]);
            }
        }
        v2.clear();
        v2 = tmp;
        tmp.clear();
    }

    int win1 = 0;
    int win2 = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] > v2[j]) {
                win1++;
            } else if (v1[i] < v2[j]) {
                win2++;
            }
        }
    }
    if (win1 > win2 && win1 > maxWin) {
        maxWin = win1;
        maxWinDices.clear();
        for (int i = 0; i < n / 2; i++) {
            maxWinDices.push_back(comb[i]);
        }
    } else if (win2 > win1 && win2 > maxWin) {
        maxWin = win2;
        maxWinDices.clear();
        for (int i = 0; i < n / 2; i++) {
            maxWinDices.push_back(remain[i]);
        }
    }
}

void combination(int n, vector<vector<int>> dice, int depth, int next) {
    if (depth == n / 2) {
        for (int i = 0; i < n / 2; i++) {
            visited[comb[i]] = true;
        }
        remainSize = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                remain[remainSize++] = i;
            }
        }
        for (int i = 0; i <= 10; i++) {
            visited[i] = 0;
        }

        diceSum(n, dice);
        return;
    }

    for (int i = next; i <= n; i++) {
        comb[depth] = i;
        combination(n, dice, depth + 1, i + 1);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    combination(dice.size(), dice, 0, 1);

    return maxWinDices;
}