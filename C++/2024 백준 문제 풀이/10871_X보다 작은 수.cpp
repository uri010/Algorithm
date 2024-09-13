//
// Created by 김유리 on 9/13/24.
//
#include <iostream>
using namespace std;

int main () {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, X, A;
    cin >> N >> X;

    for(int i=0; i< N; i++){
        cin >> A;
        if( A < X) cout << A << " ";
    }
}