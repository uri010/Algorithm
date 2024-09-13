//
// Created by 김유리 on 2024/03/02.
//
#include <iostream>

using namespace std;

int N;
string firstName;
int alphabet[27];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> firstName;
        alphabet[firstName[0] - 'a']++;
    }

    bool flag = false;
    for (int i = 0; i < 27; i++) {
        if (alphabet[i] >= 5) {
            char ans = i + 'a';
            cout << ans;
            flag = true;
        }
    }
    if (!flag) {
        cout << "PREDAJA";
    }


}