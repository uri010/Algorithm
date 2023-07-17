//
// Created by 김유리 on 2023/07/17.
//
#include <iostream>
#include <set>

using namespace std;

int N, x;
multiset<int> m;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    multiset<int>::iterator mid;

    cin >> x;
    m.insert(x);
    mid = m.begin();
    cout << *mid << "\n";

    int left = 0, right = 0;

    for (int i = 1; i < N; i++) {
        cin >> x;
        m.insert(x);

        if (x < *mid) left++;
        else right++;

        if (left - right >= 1) {
            left--;
            right++;
            --mid;
        } else if (right - left >= 2) {
            left++;
            right--;
            ++mid;
        }
        cout << *mid << "\n";
    }
}