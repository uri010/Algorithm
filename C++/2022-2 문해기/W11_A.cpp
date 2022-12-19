//
// Created by 김유리 on 2022/11/15.
//
#include <iostream>
#include <cmath>

using namespace std;

int t, n, k;
long long ans1;
long long ans2;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        ans1 = 0, ans2 = 1;
        k = 1;
        while (n != 1) {
            n /= 2;
            k++;
        }
        int i=2;
        for(;i <k; i++) {
            ans1 += (i - 1) * pow(2, i- 2);
            ans2 += (i - 1) * pow(2, i- 2) + pow(2, i- 1);
        }
        ans1 += i-1;
        ans2 += 1;
        cout << ans1 << " " << ans2 << "\n";
    }
}