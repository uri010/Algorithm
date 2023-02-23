//
// Created by 김유리 on 2022/06/28.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool iscapital (char x) {
    if( x >='A' && x <='Z') return true;
    else return false;
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string input;
    cin >> input;

    bool isFirstCap = false; //첫문자가 소문자인지 대문자인지 구별 (대-true, 소-false)
    bool isCapsLock = false; //마름모가 활성화되면 true 비활성화 false
    bool isUpper = false; // 현재 문자들이 대문자면 true 소문자면 false

    vector<int> v;
    int total = 0;

    if( isupper(input[0])) {
        isFirstCap = true;
        isUpper = true;
    }
    int cnt =0;
    for(int i=0; i < input.size(); i++){
        if( isUpper && iscapital(input[i])) {
            cnt++;
            total++;
        }
        else if(isUpper&& !iscapital(input[i])){
            v.push_back(cnt);
            cnt =1;
            isUpper = false;
            total++;
        }
        else if( !isUpper && iscapital(input[i])){
            v.push_back(cnt);
            cnt =1;
            isUpper = true;
            total++;
        }
        else if( !isUpper && !iscapital(input[i])){
            cnt++;
            total++;
        }
    }
    v.push_back(cnt);

    if( isFirstCap){
        for(int j=0; j < v.size() ;j++){
            if( isCapsLock == true && j % 2==1) {
                if( v[j] == 1) total++;
                else if( v[j] > 1) {
                    isCapsLock= false;
                    total++;
                }
            }
            else if( !isCapsLock && j % 2==0) {
                if( v[j] == 1) total++;
                else if( v[j] >1 ) {
                    isCapsLock = true;
                    total++;
                }
            }
        }
    }
    else {
        for(int j=0;j < v.size() ; j++){
            if( isCapsLock && j % 2== 0) {
                if( v[j] == 1) total++;
                else if( v[j] >1 ) {
                    isCapsLock = false;
                    total++;
                }
            }else if( !isCapsLock && j % 2== 1) {
                if( v[j] == 1) total++;
                else if( v[j] >1 ) {
                    isCapsLock = true;
                    total++;
                }
            }
        }
    }
    cout << total ;

}