//
// Created by 김유리 on 2024/01/27.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long A, B;
long long d[55];

long long countOne(long long num) {
    long long ret = num & 1;

    for (int i = 54; i > 0; i--) {
        if (num & ((long long) 1 << i)) {
            ret += d[i - 1] + (num - ((long long) 1 << i) + 1);
            num -= (long long) 1 << i;
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> A >> B;

    d[0] = 1;
    for(int i=1; i < 55; i++){
        d[i] = 2 * d[i - 1] + ((long long)1 << i); // 1 <<i는 2^i를 의미
    }

    cout << countOne(B) - countOne(A-1);
}

/*
 * 최상위 비트가 i번 이하인 모든 수의 1의 개수의 누적합 => d[i] = 2 * d[i-1] + 2^i
 * 11010(2)일 때
 * 4번 비트(1____) => 10000 미만의 모든 수의 1의 개수 + 10000~11010까지의 개수(1이 1개씩)
 * 3번 비트(01___) => 1000 미만의 모든 수의 1의 개수 + 11000~11010까지의 개수 (1이 1개씩)
 * 1번 비트(0001_) => 10 미만의 모든 수의 1의 개수 + 11010~11010까지의 개수 (1이 1개씩)
 *
 */