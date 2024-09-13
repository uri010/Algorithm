//
// Created by 김유리 on 2023/10/05.
//
#include <iostream>

using namespace std;

int N, M;
int sex, num;
int switches[101];

void Male(int n) {
    for (int i = n; i <= N; i += n) {
        switches[i] = (switches[i] + 1) % 2;
    }
}

void Female(int n) {
    int left = n - 1;
    int right = n + 1;

    switches[n] = (switches[n] + 1) % 2;
    while (left >= 1 && right <= N) {
        if (switches[left] != switches[right]) break;
        switches[left] = (switches[left] + 1) % 2;
        switches[right] = (switches[right] + 1) % 2;
        left--;
        right++;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> switches[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> sex >> num;
        if (sex == 1) Male(num);
        else Female(num);
    }

    for (int i = 1; i <= N; i++) {
        cout << switches[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
}
