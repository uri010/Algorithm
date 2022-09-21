#include <iostream>

typedef long long int ll;
using namespace std;

int t;
ll m;
int day;

void Solve() {
    ll rest = m % 10;

    if (rest > 5) {
        m += 10 - rest;
        day += 10 - rest;
    } else if (rest == 5) {
        ll next_rest = m / 10 % 10;
        if (next_rest >= 5) {
            m += rest;
            day += rest;
        } else {
            m -= rest;
            day += rest;
        }
    } else {
        m -= rest;
        day += rest;
    }
    m /= 10;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> m;
        day = 0;

        for (int i = 0; i < 11; i++) {
            Solve();
            if (m == 0) {
                cout << day << "\n";
                break;
            }
        }
    }


}