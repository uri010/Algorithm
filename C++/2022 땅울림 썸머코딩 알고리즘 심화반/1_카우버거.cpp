//
// Created by 김유리 on 2022/08/05.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int b, c, d;
int x;
vector<vector<int>> menu;
vector<pair<int, int> > compare;


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> b >> c >> d;
    menu.resize(4);
    int total = 0;
    for (int i = 0; i < b; i++) {
        cin >> x;
        menu[0].push_back(-x);
        total += x;
    }
    for (int i = 0; i < c; i++) {
        cin >> x;
        menu[1].push_back(-x);
        total += x;
    }
    for (int i = 0; i < d; i++) {
        cin >> x;
        menu[2].push_back(-x);
        total += x;
    }
    sort(menu[0].begin(), menu[0].end());
    sort(menu[1].begin(), menu[1].end());
    sort(menu[2].begin(), menu[2].end());

    compare.push_back({b, 0});
    compare.push_back({c, 1});
    compare.push_back({d, 2});
    sort(compare.begin(), compare.end());


    int sale = 0;
    for (int i = 0; i < menu[compare[0].second].size(); i++) {
        sale = sale + (-menu[compare[0].second][i]) * 0.9;
    }
    for (int i = 1; i <= 2; i++) {
        int rest = compare[i].first - compare[0].first;
        for (int j = 0; j < menu[compare[i].second].size() - rest; j++) {
            sale = sale + ((-menu[compare[i].second][j]) * 0.9);
        }
        for (int j = menu[compare[i].second].size() - rest; j < menu[compare[i].second].size(); j++) {
            sale = sale + (-menu[compare[i].second][j]);
        }

    }
    cout << total << "\n" << sale;

}