//
// Created by 김유리 on 2022/12/08.
//
#include <iostream>
#include <stack>
using namespace std;

int t;
string s;
stack <int> st;

int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while( t-- ) {
        cin >> s;
        while( !st.empty()) st.pop();
        for(int i=0; i <s.size(); i++){
            if( s[i] -'0' > 0 ) {
                st.push(s[i] - '0');
            }
            else {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                switch (s[i]) {
                    case '+':
                        st.push(n1+n2);
                        break;
                    case '-':
                        st.push(n2-n1);
                        break;
                    case '*':
                        st.push(n1*n2);
                        break;
                }
            }
        }
        cout << st.top() << "\n";
    }
}