//
// Created by 김유리 on 2023/07/13.
//
#include <iostream>
#include <set>

using namespace std;

int T, k, n;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    string s;
    while (T--) {
        cin >> k;
        multiset<int> ms;
        while (k--) {
            cin >> s;
            if (s == "I") {
                cin >> n;
                ms.insert(n);
            } else if (s == "D") {
                cin >> n;
                if (ms.empty()) continue;
                else if (n == 1) {
                    ms.erase(--ms.end());
                } else if (n == -1) {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty()) cout << "EMPTY\n";
        else {
            multiset<int>::iterator min_iter = ms.begin();
            multiset<int>::iterator max_iter = ms.end();
            max_iter--;
            cout << *max_iter << " " << *min_iter << "\n";
        }
    }
}