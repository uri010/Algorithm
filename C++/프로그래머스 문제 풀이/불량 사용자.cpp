//
// Created by 김유리 on 2023/12/21.
//
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

set<string> idList;

bool isSame(string a, string b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '*' || a[i] == b[i]) {
                continue;
            }
            return false;
        }
    } else return false;
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    sort(user_id.begin(), user_id.end());

    do {
        vector<string> tmp;
        string id = "";
        for (int i = 0; i < banned_id.size(); i++) {
            if (isSame(banned_id[i], user_id[i])) {
                tmp.push_back(user_id[i]);
            }
        }

        if (tmp.size() == banned_id.size()) {
            sort(tmp.begin(), tmp.end());
            for (const auto &t: tmp) {
                id += t;
            }
            idList.insert(id);
        }
    } while (next_permutation(user_id.begin(), user_id.end()));

    return idList.size();
}