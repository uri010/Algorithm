//
// Created by 김유리 on 2023/10/10.
//
#include <iostream>
#include <string>

using namespace std;

int N, K, cnt;
string str;
bool visited[20001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        int flag = 0;
        if (str[i] == 'P') {
            for (int j = K; j >= 1; j--) {
                if (i - j >= 0) {
                    if (str[i - j] == 'H' && !visited[i - j]) {
                        visited[i - j] = true;
                        cnt++;
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag) {
                for (int j = 1; j <= K; j++) {
                    if (i + j < N) {
                        if (str[i + j] == 'H' && !visited[i + j]) {
                            visited[i + j] = true;
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}