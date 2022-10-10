#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, pair<int, int>>> v;
bool disk[21];
int t, n, k;


void hanoi(int x, int from, int tmp, int to) {
    if (x == 1) {
        v.push_back({x, {from, to}});
        return;
    } else {
        hanoi(x - 1, from, to, tmp);
        v.push_back({x, {from, to}});
        hanoi(x - 1, tmp, from, to);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(disk, false, sizeof(disk));
        v.clear();
        hanoi(n, 1, 2, 3);
        for (int i = 0; i < k; i++) {
            if (v[i].second.first == 2) {
                disk[v[i].first] = false;
            } else if (v[i].second.second == 2) {
                disk[v[i].first] = true;
            }
        }
        int flag = 0;
        for (int i = 0; i < 21; i++) {
            if (disk[i]) {
                cout << i << " ";
                flag = 1;
            }
        }
        if( flag == 0) cout << "0";
        cout << "\n";
    }
}