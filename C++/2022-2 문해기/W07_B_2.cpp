//
// Created by 김유리 on 2022/12/08.
//
#include <iostream>
using namespace std;

int t;
string s;

int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while( t-- ) {
        cin >> s;
        int max_length = 0;
        for(int i=0; i <s.size() ;i++){
            int male =0, female =0;
            for(int j=i; j<s.size(); j++){
                if( s[j] == '0') male++;
                else female++;
                if( male == female) {
                    max_length = max(max_length , male*2);
                }
            }
        }
        cout << max_length << "\n";
    }
}