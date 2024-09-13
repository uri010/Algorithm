//
// Created by 김유리 on 2024. 9. 13..
//
#include <iostream>
using namespace std;

int main (){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int alpha[26] = {0, };

    for(char i : s){
        alpha[i-'a']++;
    }
    for(int i : alpha){
        cout << i << " " ;
    }
}