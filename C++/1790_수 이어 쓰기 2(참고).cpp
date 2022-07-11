//
// Created by 김유리 on 2022/07/11.
//
#include <iostream>
#include <math.h>

using namespace std;

long long n, k;
long long total;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    string str = to_string(n);
    long long i;
    for (i = 1; i <= str.size(); i++) {
        if (total < k && total + i * ((long long) pow(10, i) - (long long) pow(10, i - 1)) >= k) {
            break;
        } else {
            total += i * ((long long) pow(10, i) - (long long) pow(10, i - 1));
        }
    }

    k = k - total;
    int seq = k / i;
    int seq2 = k % i;
    int ans;
    int num = pow(10, i - 1) + seq - 1;
    if (n < num) {
        ans = -1;
    } else {
        string tmp = "";
        if (seq2 == 0) {
            tmp = to_string(num);
            ans = tmp[tmp.size() - 1] - '0';
        } else {
            num += 1;
            if (n < num) {
                ans = -1;
            } else {
                tmp = to_string(num);
                ans = tmp[seq2 - 1] - '0';
            }
        }
    }
    cout << ans << endl;
    return 0;

}