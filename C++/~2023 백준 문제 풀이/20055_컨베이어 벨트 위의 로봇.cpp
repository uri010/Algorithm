//
// Created by 김유리 on 2023/10/30.
//
#include <iostream>

using namespace std;

int N, K, A;
int arr[1002];
bool robot[1002];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> arr[i];
    }
    int zeroCnt =0 ;
    int ans = 0;
    while (zeroCnt < K) {
        ans++;

        int tmp = arr[2*N];
        for (int i = 2*N; i >= 2; i--) {
            arr[i] = arr[i-1];
            robot[i] = robot[i-1];
        }
        arr[1] = tmp;
        robot[1] = false;

        robot[N] = false;

        if( robot[N-1] && !robot[N] && arr[N] >= 1) {
            robot[N-1] = false;
            if( --arr[N] == 0 ) zeroCnt++;
        }

        for(int i=N-2; i>= 1; i--) {
            if( robot[i] && !robot[i+1] && arr[i+1] >= 1) {
                robot[i] = false;
                robot[i+1] = true;
                if( --arr[i+1] == 0 ) zeroCnt++;
            }
        }
        if( arr[1] != 0 ) {
            robot[1] = true;
            if( --arr[1] == 0 ) zeroCnt++;
        }
    }
    cout << ans;

}