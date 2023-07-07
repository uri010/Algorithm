//
// Created by 김유리 on 2023/07/07.
//
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    list<int> li;
    for (int i = 1; i <= N; i++) {
        li.push_back(i);
    }
    list<int>::iterator cur = li.begin();
    vector<int> ans;
    int cnt = 1;
    while (!li.empty()) {
        if (cnt == K) {
            list<int>::iterator next = cur;
            if (++next == li.end()) {
                next = li.begin();
            }
            ans.push_back(*cur);
            li.erase(cur);
            cnt = 1;
            cur = next;
        } else {
            cnt++;
            if (++cur == li.end()) {
                cur = li.begin();
            }
        }
    }
    cout << "<";
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size() - 1] << ">";
}
