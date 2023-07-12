//
// Created by 김유리 on 2023/07/12.
//
#include <iostream>
#include<sstream>
#include <istream>
#include <map>

using namespace std;

int N;
int arr[101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    cin.ignore();
    string s, L;
    map<string, pair<int, int>> m;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        istringstream ss(s);
        string tmp;
        int j = 0;
        while (getline(ss, tmp, ' ')) {
            m.insert({tmp, {i, j}});
            j++;
        }
    }
    getline(cin, L);
    istringstream LL(L);
    string tmp;
    bool flag = true;
    while (getline(LL, tmp, ' ')) {
        if (m.find(tmp) != m.end()) {
            if (arr[m.at(tmp).first] == m.at(tmp).second) {
                arr[m.at(tmp).first]++;
                m.erase(m.find(tmp));
            } else {
                flag = false;
                break;
            }
        } else {
            flag = false;
            break;
        }
    }
    if (flag && m.empty()) cout << "Possible";
    else cout << "Impossible";
}