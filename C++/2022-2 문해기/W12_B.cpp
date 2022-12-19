#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int t, n, p;
multiset<pair<int, int>> ms;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> p;
        ms.clear();
        ms.insert({p, 1});
        cout << -1 << " ";
        for (int i = 2; i <= n; i++) {
            cin >> p;
            ms.insert({p, i});
            auto iter = ms.find({p, i});
            if (iter == ms.begin()) cout << -1 << " ";
            else {
                iter--;
                cout << iter->second << " ";
            }
        }
    }
}