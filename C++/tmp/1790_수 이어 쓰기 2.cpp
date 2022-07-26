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
    if (total == 0) {
        if (k > n) {
            cout << -1;
        } else {
            cout << k;
        }
        return 0;
    }
    for (int j = pow(10, i - 1); j <= n; j++) {
        string num = to_string(j);
        if (total < k && total + num.size() >= k) {
            for (int l = 0; l < num.size(); l++) {
                total++;
                if (total == k) {
                    cout << num[l];
                    return 0;
                }
            }
        } else {
            total = total + num.size();
        }
    }
    cout << -1;
    return 0;


}