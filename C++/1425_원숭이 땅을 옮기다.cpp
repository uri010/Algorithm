//
// Created by 김유리 on 2022/07/21.
//
#include <iostream>
#include <vector>
#include <stdlib.h>
#define INF 2100000000

using namespace std;

vector<pair<int, int>> monkey;
int n;
int max_dist;

int solve(int mid) {
    int max_y1 = -1000000000;
    int max_y2 = -1000000000;
    for (int i = 0; i < n; i++) {
        int x1 = monkey[i].first;
        int y1 = monkey[i].second - mid;
        for (int j = i + 1; j < n; j++) {
            int x2 = monkey[j].first;
            int y2 = monkey[j].second - mid;
            //같은 나무인 경우
            if (x1 == x2) {
                if (max_dist < abs(y1 - y2)) {
                    max_dist = abs(y1 - y2);
                    max_y1 = y1;
                    max_y2 = y2;
                }
            }
                //다른 나무인 경우
            else {
                if (max_dist < abs(y1) + abs(y2) + abs(x1 - x2)) {
                    max_dist = abs(y1)+ abs(y2) + abs(x1 - x2);
                    max_y1 = y1;
                    max_y2 = y2;
                }
            }
        }
    }
    if ((max_y1 >= 0 && max_y2 < 0) || (max_y1 < 0 && max_y2 >= 0))
        return -1;
    else if (max_y1 >= 0 && max_y2 >= 0)
        return 1;
    else if (max_y1 < 0 && max_y2 < 0)
        return 0;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    int x, y;
    int left = 1000000000;
    int right = -1000000000;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        monkey.push_back({x, y});
        left = min(left, y);
        right = max(right, y);
    }
    if ((left >= 0 && right >= 0) || (left < 0 && right < 0)) {
        max_dist =0;
        for (int i = 0; i < n; i++) {
            int x1 = monkey[i].first;
            int y1 = monkey[i].second;
            for (int j = i; j < n; j++) {
                int x2 = monkey[j].first;
                int y2 = monkey[j].second;
                //같은 나무인 경우
                if (x1 == x2) {
                    if (max_dist < abs(y1 - y2)) {
                        max_dist = abs(y1 - y2);
                    }
                }
                    //다른 나무인 경우
                else {
                    if (max_dist < abs(y1 - y2) + abs(x1 - x2)) {
                        max_dist = abs(y1 - y2) + abs(x1 - x2);
                    }
                }
            }
        }
        cout << max_dist;
        return 0;
    }

    int result =0;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        max_dist = 0;
        int case_num = solve(mid);
        if (case_num == -1) {
            result = max_dist;
            break;
        } else if (case_num == 1) {
            result = max_dist;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result;


}