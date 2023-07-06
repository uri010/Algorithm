//
// Created by 김유리 on 2023/07/06.
//
#include <iostream>
#include <string>
#include <list>

using namespace std;


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    list<char> li;

    for (int i = 0; i < s.size(); i++) {
        li.push_back(s[i]);
    }

    int M;
    cin >> M;

    list<char>::iterator cur = li.end();
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (s == "L") {
            if (cur != li.begin())
                cur--;
        } else if (s == "D") {
            if (cur != li.end())
                cur++;
        } else if (s == "B") {
            if (cur != li.begin()) {
                list<char>::iterator tmp = cur;
                li.erase(--cur);
                cur = tmp;
            }
        } else if (s == "P") {
            char x;
            cin >> x;
            li.insert(cur, x);
        }
    }
    for (auto iter = li.begin(); iter != li.end(); iter++) {
        cout << *iter;
    }

}