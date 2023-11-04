//
// Created by 김유리 on 2023/11/04.
//
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int N;
int input[101];
bool visited[101];
set<int> answer;
bool isRight;

void DFS(int firstNum, int num) {
    if (visited[num]) {
        if (firstNum == num) {
            isRight = true;
            answer.insert(num);
        }
        return;
    }
    visited[num] = true;
    DFS(firstNum, input[num]);
    if (isRight) {
        answer.insert(num);
        answer.insert(input[num]);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        DFS(i, input[i]);
        memset(visited, false, sizeof(visited));
        isRight = false;
    }

    cout << answer.size() << '\n';
    for (auto a: answer) {
        cout << a << "\n";
    }

}