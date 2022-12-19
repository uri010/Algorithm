#include <iostream>
#include <vector>

using namespace std;

int t, n, d, x;
int calorie[100002];
int weight[202];
int ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> d;
        ans = 0;
        for (int i = 1; i <= d; i++) {
            cin >> x;
            calorie[i] = x;
            weight[x]++;
        }
        for (int i = d + 1; i <= n; i++) {
            cin >> x;
            calorie[i] = x;
            int cnt = 0, prev = 0;
            int mid;
            for (mid = 0; mid <= 200; mid++) {
                cnt += weight[mid];
                if (cnt > d / 2)
                    break;
                if (weight[mid] > 0)
                    prev = mid;
            }
            if (d % 2) {
                if (mid * 2 <= calorie[i])
                    ans++;
            } else {
                if (cnt - weight[mid] == d / 2) {
                    mid += prev;
                } else {
                    mid += mid;
                }
                if (mid <= calorie[i]) ans++;
            }
            weight[x]++;
            weight[calorie[i - d]]--;
        }
        cout << ans << "\n";
        for(int i=0; i <=200; i++) weight[i] =0;
    }
    return 0;
}