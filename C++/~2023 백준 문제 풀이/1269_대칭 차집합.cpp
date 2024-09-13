//
// Created by 김유리 on 2022/05/16.
//
#include <iostream>
#include <map>
using namespace std;

int main (){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<int, int> m;
    int A[200001];
    int B[200001];

    int a, b;
    int ans =0;
    cin >> a >> b;
    for(int i=0; i < a; i++){
        cin >> A[i];
        m[A[i]]++;
    }
    for(int i=0; i <b; i++){
        cin >> B[i];
        if(m[B[i]]) ans++;
    }
    cout << a+b-(ans*2);


}