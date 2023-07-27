//
// Created by 김유리 on 2023/07/27.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[22][22];
bool visited[22];
int ans = 1000000000;

void DFS(int cnt, int x) {
    if (cnt == N / 2) {
        int ts = 0, tl = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visited[i] && visited[j]) ts += arr[i][j];
                if (!visited[i] && !visited[j]) tl += arr[i][j];
            }
        }
        int tmp = abs(ts - tl);
        if (ans > tmp) ans = tmp;
        return;
    }
    for (int i = x; i < N; i++) {
        visited[i] = true;
        DFS(cnt + 1, i + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    DFS(0, 1);
    cout << ans;

}