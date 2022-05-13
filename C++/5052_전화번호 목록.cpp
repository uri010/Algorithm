#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool solution(vector<string> phone) {
    int idx(0), idx2(0);
    sort(phone.begin(), phone.end());
    for (idx = 0; idx < phone.size() - 1; ++idx)
        if (phone[idx] == phone[idx + 1].substr(0, phone[idx].size()))
            return false;
    return true;
}

void main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string>phone;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            phone.push_back(s);
        }
        if (solution(phone)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}