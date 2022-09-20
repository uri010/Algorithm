#include <iostream>

typedef long long int ll;
using namespace std;

int t;
ll m;
int ans;

void Solve() {
    ll rest = m % 10;

    if (rest > 5) {
        m += (10 - rest);
        ans += (10 - rest);
    } else if (rest == 5) {
        ll next_rest = m / 10 % 10;
        if (next_rest >= 5) {
            m += rest;
            ans += rest;
        }else {
            m -= ( 10 - rest);
            ans+= (10 - rest);
        }
    } else {
        m -= rest;
        ans += rest;
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
        ans = 0;

        for (int i = 0; i <12; i++){
            Solve();
            if( m== 0 ) {
                cout << ans << "\n";
                break;
            }
        }
    }


}