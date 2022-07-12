#include <iostream>

using namespace std;

int n;
int op[4];
int num[12];
int min_num = 1000000000;
int max_num = -1000000000;

void check(int x) {
    if (min_num > x) min_num = x;
    if (max_num < x) max_num = x;
}

void dfs(int idx, int cnt, int result) {
    if (cnt == n) {
        check(result);
        return;
    }
    for (int i = 0; i < 4; i++) {
        op[idx]--;
        if (op[i] > 0) {
            if (i == 0) dfs(i, cnt + 1, result + num[cnt]);
            else if (i == 1) dfs(i, cnt + 1, result - num[cnt]);
            else if (i == 2) dfs(i, cnt + 1, result * num[cnt]);
            else if (i == 3) {
                if (result < 0) dfs(i, cnt + 1, -(-result / num[cnt]));
                else dfs(i, cnt + 1, result / num[cnt]);
            }
        }
        op[idx]++;

    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int pl, mi, mu, di;
    cin >> pl >> mi >> mu >> di;
    for (int i = 0; i < 4; i++) {
        op[0] = pl;
        op[1] = mi;
        op[2] = mu;
        op[3] = di;
        if (op[i] > 0) {
            if (i == 0) {
                dfs(0, 2, num[0] + num[1]);
            } else if (i == 1) {
                dfs(1, 2, num[0] - num[1]);
            } else if (i == 2) {
                dfs(2, 2, num[0] * num[1]);
            } else if (i == 3) {
                if (num[0] < 0)
                    dfs(3, 2, -(-num[0] / num[1]));
                else
                    dfs(3, 2, num[0] / num[1]);
            }
        }
    }
    cout << max_num << "\n" << min_num;
}