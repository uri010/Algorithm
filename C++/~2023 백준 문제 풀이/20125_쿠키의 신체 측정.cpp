//
// Created by 김유리 on 2023/10/20.
//
#include <iostream>

using namespace std;

char map[1001][1001];

int Measure(int i, int j, int di, int dj) {
    int cnt = 0;
    while (map[i][j] == '*') {
        i = i + di;
        j = j + dj;
        cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    bool isHead = false;
    int iHead = 0, jHead = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (!isHead && map[i][j] == '*') {
                isHead = true;
                iHead = i;
                jHead = j;
            }
        }
    }

    int iHeart = iHead + 1;
    int jHeart = jHead;

    int leftArm = Measure(iHeart, jHeart - 1, 0, -1);
    int rightArm = Measure(iHeart, jHeart + 1, 0, 1);
    int waist = Measure(iHeart + 1, jHeart, 1, 0);

    int leftLeg = Measure(iHeart + waist + 1, jHeart - 1, 1, 0);
    int rightLeg = Measure(iHeart + waist + 1, jHeart + 1, 1, 0);

    cout << iHeart << " " << jHeart << "\n";
    cout << leftArm << " " << rightArm << " " << waist << " " << leftLeg << " " << rightLeg;


}