#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

vector<ull> v;
bool visited[101];
int n;

void Solve(vector<ull> ans) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans.back() % 3 == 0 && v[j] == ans.back() / 3) {
                ans.push_back(v[j]);
            } else if (v[j] == ans.back() * 2) {
                ans.push_back(v[j]);
            }
        }
        if (i == (n - 1)) {
            if (ans.size() == n) {
                for (int k = 0; k < n; k++) {
                    cout << ans[k] << " ";
                }
            } else {
                return;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    ull a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        vector<ull> ans;
        ans.push_back(v[i]);
        Solve(ans);
    }
}