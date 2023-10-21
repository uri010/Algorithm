//
// Created by 김유리 on 2023/10/21.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

int iStart = -1, jStart = -1;
bool visited[101][101];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
int answer;

void BFS(vector<string> board) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {iStart, jStart}});
    visited[iStart][jStart] = true;

    while (!q.empty()) {
        int cnt = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();

        if (board[i][j] == 'G') {
            answer = cnt;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int diri = di[k];
            int dirj = dj[k];

            int ni = i;
            int nj = j;

            if (diri != 0) {
                while (ni < board.size() && ni >= 0 && board[ni][j] != 'D') {
                    ni += diri;
                }
                if (!visited[ni - diri][j]) {
                    q.push({cnt + 1, {ni - diri, j}});
                    visited[ni - diri][j] = true;
                }
            } else if (dirj != 0) {
                while (nj < board[0].size() && nj >= 0 && board[i][nj] != 'D') {
                    nj += dirj;
                }
                if (!visited[i][nj - dirj]) {
                    q.push({cnt + 1, {i, nj - dirj}});
                    visited[i][nj - dirj] = true;
                }
            }
        }
    }
}

int solution(vector<string> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'R') {
                iStart = i;
                jStart = j;
                break;
            }
        }
        if (iStart != -1)
            break;
    }

    BFS(board);
    if (answer != 0) return answer;
    return -1;
}