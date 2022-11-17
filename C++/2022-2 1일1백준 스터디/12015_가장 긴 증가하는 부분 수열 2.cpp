//
// Created by 김유리 on 2022/11/16.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int arr[1000001];
vector<int> v;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    v.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (v.back() < arr[i]) v.push_back(arr[i]);
        else {
            auto iter = lower_bound(v.begin(), v.end(), arr[i]);
            *iter = arr[i];
        }
    }
    cout << v.size();
}