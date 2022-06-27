//
// Created by 김유리 on 2022/06/27.
//
#include <iostream>
#include <string>
using namespace std;

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    int n;
    cin >> n;
    cin >> str;
    char comp = str[str.size()-1];
    if( comp=='y' ||  comp == 'u'|| comp=='i' || comp=='o'||comp=='p'||comp=='h'||
    comp =='j' || comp=='k' || comp=='l' || comp=='b' || comp=='n'||comp=='m'){
        cout << 0;
    }else cout << 1;


}