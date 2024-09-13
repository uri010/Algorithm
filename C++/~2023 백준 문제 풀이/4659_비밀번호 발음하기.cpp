//
// Created by 김유리 on 2024/03/07.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    while (str != "end") {
        int coCnt = 0;
        int voCnt = 0;
        bool isVowels = false;
        bool isThree = false;
        char prev = ' ';
        bool isTwo = false;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u') {
                isVowels = true;
                coCnt = 0;
                if (++voCnt == 3) {
                    isThree = true;
                    break;
                }
                if (prev != ' ' && prev == str[i]) {
                    if (prev != 'e' && prev != 'o') {
                        isTwo = true;
                        break;
                    }
                }
            } else {
                voCnt = 0;
                if (++coCnt == 3) {
                    isThree = true;
                    break;
                }
                if (prev != ' ' && prev == str[i]) {
                    isTwo = true;
                    break;
                }
            }
            prev = str[i];
        }
        if (!isVowels || isThree || isTwo) {
            cout << "<" << str << "> is not acceptable.\n";
        } else {
            cout << "<" << str << "> is acceptable.\n";
        }

        cin >> str;
    }

}