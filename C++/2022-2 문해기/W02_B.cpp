#include <iostream>
#include <set>

using namespace std;

int t, m, n, x;
string s;
multiset<int> ms;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> m >> n;
        ms.clear();
        for (int i = 0; i < m; i++) {
            cin >> x;
            ms.insert(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == "Delete") {
                cin >> s;
                if (s == "max") {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                } else if (s == "min") {
                    auto iter = ms.begin();
                    ms.erase(iter);
                }
            } else if (s == "Add") {
                cin >> x;
                ms.insert(x);
            }
        }
        auto begin_num = ms.begin();
        auto end_num = ms.end();
        end_num--;
        cout << *begin_num << " " << *end_num << "\n";
    }

}