#include <iostream>
#include <vector>

using namespace std;
#define INF 2100000000

int T, n, D;


void matrixChainOrder(vector<int> &p, vector<vector<int> > &m,
                      vector<vector<int> > &s) { // 최소 곱셈 연산 수는 배열 m에, 최소 곱셈 연산 수가 나오기 위한 연산 순서 정보는 s에 저장
    for (int i = 0; i < n; i++)  // 하나의 행렬은 0으로 초기화
        m[i][i] = 0;

    // 행렬의 길이(개수) l을 2부터 n까지 최소 곱셈 연산 수를 계산
    for (int l = 2; l <= n; l++) {
        //m[i][j]에는 Ai부터 Aj까지의 행렬을 곱할 때 최소 연산 수를 계산해 저장
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INF; // 배열 m에 최소 곱셈 연산 수를 넣어 주기 위해 큰 값으로 초기화
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j]) { // 기존의 값보다 새로 계산한 q가 더 작다면 q로 업데이트하고 연산 순서를 s에 저장
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}


void printOptimalParens(vector<vector<int> > &ans, vector<vector<int> > &m, vector<vector<int> > &s, int i,
                        int j) { //최소 곱셈 연산 수가 나오는 연산 순서대로 곱하는 함수
    if (i == j) {
        ans[i][j] = i;
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(ans, m, s, i, s[i][j]);
        printOptimalParens(ans, m, s, s[i][j] + 1, j);
        cout << ")";

        int x = ans[i][s[i][j]] * ans[i][s[i][j]];
        int y = ans[s[i][j] + 1][j] * ans[s[i][j] + 1][j];
        ans[i][j] = (x + y) % D;
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> D;
        vector<int> p(n + 1); // 입력으로 주어지는 차원 값 p를 저장하는 배열
        vector<vector<int>> m(n + 1, vector<int>(n + 1)); // 곱셈 연산 수를 저장하는 배열
        vector<vector<int>> s(n + 1, vector<int>(n + 1)); // 최소 곱셈 연산을 했을 때 중간 위치를 나타내는 k값을 저장하는 배열
        vector<vector<int>> ans(n + 1, vector<int>(n + 1)); // 연산 순서대로 곱하면서 z 값을 구하기 위해 필요한 배열

        for (int i = 0; i <= n; i++) {
            cin >> p[i];
        }

        matrixChainOrder(p, m, s);
        printOptimalParens(ans, m, s, 1, n);

        cout << m[1][n] << "\n"; // 1부터 n번째 행렬을 곱할 때의 최소 곱셈 연산 수 출력
        cout << ans[1][n] << "\n"; // 1부터 n번째 행렬을 곱할 때 최소 곱셈 연산 수가 나오도록 연산을 할 경우 C의 최종 z 값 출력
    }
}