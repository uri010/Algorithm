//
// Created by 김유리 on 2023/07/07.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    string website, pwd;
    map<string, string> m;
    for (int i = 0; i < N; i++) {
        cin >> website >> pwd;
        m.insert({website, pwd});
    }
    for (int i = 0; i < M; i++) {
        cin >> website;
        cout << m[website] << "\n";
    }

}