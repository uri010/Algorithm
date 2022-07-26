//
// Created by 김유리 on 2022/07/18.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int n, m;
string first_king;
string input[51][3];

map<string, pair<pair<string, string>, double>> family;

void solve(string child, string par_left, string par_right) {
    if (family[child].second == 0) {
        if (family.count(par_left) && family.count(par_right)) {
            double left_num = family[par_left].second;
            double right_num = family[par_right].second;
            if (left_num != 0 && right_num != 0) {
                family[child] = {{par_left, par_right}, left_num / 2 + right_num / 2};
            } else if (left_num != 0 && right_num == 0) {
                solve(par_left, family[par_left].first.first, family[par_left].first.second);
                right_num = family[par_left].second;
                family[child] = {{par_left, par_right}, left_num / 2 + right_num / 2};
            } else if (left_num == 0 && right_num != 0) {
                solve(par_right, family[par_right].first.first, family[par_right].first.second);
                left_num = family[par_right].second;
                family[child] = {{par_left, par_right}, left_num / 2 + right_num / 2};
            } else {
                solve(par_left, family[par_left].first.first, family[par_left].first.second);
                right_num = family[par_left].second;
                solve(par_right, family[par_right].first.first, family[par_right].first.second);
                left_num = family[par_right].second;
                family[child] = {{par_left, par_right}, left_num / 2 + right_num / 2};
            }
        } else if (family.count(par_left) && !family.count(par_right)) {
            double left_num = family[par_left].second;
            if (left_num != 0) {
                family[child] = {{par_left, par_right}, left_num / 2};
            } else {
                solve(par_left, family[par_left].first.first, family[par_left].first.second);
                left_num = family[par_left].second;
                family[child] = {{par_left, par_right}, left_num / 2};
            }
        } else if (!family.count(par_left) && family.count(par_right)) {
            double right_num = family[par_right].second;
            if (right_num != 0) {
                family[child] = {{par_left, par_right}, right_num / 2};
            } else {
                solve(par_right, family[par_right].first.first, family[par_right].first.second);
                right_num = family[par_left].second;
                family[child] = {{par_left, par_right}, right_num / 2};
            }
        }
        return;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> first_king;

    family.insert({first_king, {{"", ""}, 1}});
    string a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        family.insert({a, {{b, c}, 0}});
        input[i][0] = a;
        input[i][1] = b;
        input[i][2] = c;
    }
    for (int i = 0; i < n; i++) {
        string child = input[i][0];
        string par_left = input[i][1];
        string par_right = input[i][2];

        if (family[child].second == 0) {
            solve(child, par_left, par_right);
        }
    }


    string s;
    double large = 0;
    string large_man = "";
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (large < family[s].second) {
            large_man = s;
            large = family[s].second;
        }
    }
    cout << large_man;


}