//
// Created by 김유리 on 2023/09/05.
//
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> chat;
    map<string, string> members;

    for (int i = 0; i < record.size(); i++) {
        vector<string> order = split(record[i], ' ');

        if (order[0] == "Enter") {
            chat.push_back({"Enter", order[1]});
            if (members.find(order[1]) == members.end()) {
                members.insert({order[1], order[2]});
            }
            members[order[1]] = order[2];
        } else if (order[0] == "Leave") {
            chat.push_back({"Leave", order[1]});
        } else {
            members[order[1]] = order[2];
        }
    }

    for (int i = 0; i < chat.size(); i++) {
        string message = chat[i].first;
        string id = chat[i].second;

        if (message == "Enter") {
            answer.push_back(members[id] + "님이 들어왔습니다.");
        } else if (message == "Leave") {
            answer.push_back(members[id] + "님이 나갔습니다.");
        }
    }

    return answer;
}