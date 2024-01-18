//
// Created by 김유리 on 2024/01/19.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(), timetable.end());

    int busTime = 9 * 60;
    int index = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int ttime = 0;
        while (cnt < m && index < timetable.size()) {
            int thour = (timetable[index][0] - '0') * 10 + (timetable[index][1] - '0');
            int tmin = (timetable[index][3] - '0') * 10 + (timetable[index][4] - '0');
            ttime = thour * 60 + tmin;
            if (ttime <= busTime) {
                cnt++;
                index++;
            } else break;
        }
        if (i == n - 1) {
            if (cnt < m) {
                string hour = to_string(busTime / 60);
                if (hour.size() == 1) {
                    hour = "0" + hour;
                }
                string min = to_string(busTime % 60);
                if (min.size() == 1) {
                    min = "0" + min;
                }
                answer += hour + ":" + min;
            } else if (cnt >= m) {
                ttime -= 1;
                string hour = to_string(ttime / 60);
                if (hour.size() == 1) {
                    hour = "0" + hour;
                }
                string min = to_string(ttime % 60);
                if (min.size() == 1) {
                    min = "0" + min;
                }
                answer += hour + ":" + min;
            }
        }
        busTime += t;
    }
    return answer;
}