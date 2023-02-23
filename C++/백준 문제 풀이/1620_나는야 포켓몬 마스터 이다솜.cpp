#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;

int main (){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unordered_map<string, int> um;
    string arr[100001];

    int n, m;
    cin >> n >> m;
    string s;
    for(int i=1; i <=n;i++){
        cin >> s;
        um.insert(make_pair(s, i));
        arr[i] = s;
    }

    for(int i=0;i <m;i++){
        cin >> s;
        if( isdigit(s[0]) ){
            cout << arr[stoi(s)] << "\n";
        }
        else {
            cout << um[s] << "\n";
        }
    }
}