//
// Created by 김유리 on 2024/01/19.
//
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, L, R;
int arr[51][51];
bool visited[51][51];
vector<pair<int, int>> uni;
bool isUnion = true;
int sum, days;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    uni.push_back({i, j});
    visited[i][j] = true;
    sum = arr[i][j];

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= N || nj >= N || visited[ni][nj]) continue;

            if (abs(arr[ni][nj] - arr[i][j]) >= L && abs(arr[ni][nj] - arr[i][j]) <= R) {
                q.push({ni, nj});
                visited[ni][nj] = true;
                uni.push_back({ni, nj});
                sum += arr[ni][nj];
            }
        }
    }
}

void print(){
    cout << sum << "\n";
   for(int i=0; i < N; i++){
       for(int j=0;j < N; j++){
           cout << arr[i][j] << " ";
       }
       cout << "\n";
   }
   cout << "\n";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    while (isUnion) {
        isUnion = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    uni.clear();
                    BFS(i, j);
                    if (uni.size() >= 2) {
                        isUnion = true;
                        for (int k = 0; k < uni.size(); k++) {
                            arr[uni[k].first][uni[k].second] = sum / uni.size();
                        }
                    }
                }
            }
        }
        if (isUnion) days++;
        memset(visited, false, sizeof(visited));
    }
    cout << days;
}