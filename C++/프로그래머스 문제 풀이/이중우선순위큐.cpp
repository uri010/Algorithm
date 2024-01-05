//
// Created by 김유리 on 2024/01/05.
//
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

multiset<int> ms;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for (int i = 0; i < operations.size(); i++) {
        vector<string> temp = split(operations[i], ' ');
        if (temp[0] == "I") {
            ms.insert(stoi(temp[1]));
        } else if (temp[0] == "D") {
            if (ms.empty()) continue;
            multiset<int>::iterator iter = ms.begin();
            if (temp[1] == "1") {
                iter = ms.end();
                iter--;
            }
            ms.erase(iter);
        }
    }

    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        multiset<int>::iterator iter = ms.end();
        iter--;
        answer.push_back(*iter);
        answer.push_back(*ms.begin());
    }

    return answer;
}