//
// Created by 김유리 on 2023/07/25.
//
#include <iostream>
using namespace std;

long long a, b;

long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    long long ans = gcd(a, b);
    cout << ans << "\n";
    cout << (a * b) / ans;

}