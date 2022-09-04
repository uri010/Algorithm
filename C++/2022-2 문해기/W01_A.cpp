//
// Created by 김유리 on 2022/09/04.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int t, n, m, x;
vector<int> inha;
vector<int> drake;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

bool check(vector<int> &kingdom, int a){
    for(int i=0; i <kingdom.size(); i++){
        if( kingdom[i] % a == 0 ) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        inha.clear();
        drake.clear();

        for (int i = 0; i < n; i++) {
            cin >> x;
            inha.push_back(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            drake.push_back(x);
        }

        sort(inha.begin(), inha.end());
        sort(drake.begin(), drake.end());

        int inhaGcd = inha[0];
        for (int i = 1; i < n; i++) {
            if (inhaGcd > inha[i])
                inhaGcd = gcd(inhaGcd, inha[i]);
            else
                inhaGcd = gcd(inha[i], inhaGcd);
        }
        int drakeGcd = drake[0];
        for(int i=1;i <m; i++){
            if( drakeGcd > drake[i])
                drakeGcd = gcd(drakeGcd, drake[i]);
            else
                drakeGcd = gcd(drake[i], drakeGcd);
        }

        if( check(inha, drakeGcd))
            cout << drakeGcd << " ";
        else
            cout << -1 << " " ;

        if( check(drake, inhaGcd))
            cout << inhaGcd << "\n";
        else
            cout << -1 << "\n";
    }
}