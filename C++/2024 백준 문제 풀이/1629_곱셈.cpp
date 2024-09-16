//
// Created by 김유리 on 2024. 9. 17..
//
#include <iostream>

using namespace std;

using ll = long long;

ll func1(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll val = func1(a, b / 2, c);
    val = (val * val) % c;

    if (b % 2 == 0) return val;
    return val * a % c;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << func1(a, b, c);
}