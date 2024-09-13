#include <iostream>
#include <cstring>
using namespace std;

long long dp[31][31];
int n;

long long solve(int i, int j ) {
    if( j ==0 ) return 1;
    long long &ret = dp[i][j];
    if( ret != -1) return ret;
    else {
        ret =0;
        if( j > 0 ) ret += solve(i+1, j -1) ;
        if( i > 0 ) ret += solve(i-1, j);
        return ret;
    }
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> n;
        if( n== 0 ) break;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, n-1)<< "\n";
    }
    return 0;
}