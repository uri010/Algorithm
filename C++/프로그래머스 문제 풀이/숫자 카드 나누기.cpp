//
// Created by 김유리 on 2023/10/12.
//
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = 0, gcdB = 0;
    for (int i = 0; i < arrayA.size(); i++) {
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }

    if (gcdA == 0) return gcdB;
    else if (gcdB == 0) return gcdA;

    if (gcdA > gcdB) {
        bool flagA = true;
        for (int i = 0; i < arrayB.size(); i++) {
            if (arrayB[i] % gcdA == 0) {
                flagA = false;
                break;
            }
        }
        if (flagA) return gcdA;
    } else {
        bool flagB = true;
        for (int i = 0; i < arrayB.size(); i++) {
            if (arrayA[i] % gcdB == 0) {
                flagB = false;
                break;
            }
        }
        if (flagB) return gcdB;
    }
    return answer;
}