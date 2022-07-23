//
// Created by 김유리 on 2022/07/23.
//
#include <iostream>
#include <cstring>

using namespace std;

int R, C, M;
int r, c, s, d, z;
pair<int, pair<int, int>> map[102][102]; //속력, 이동방향, 크기
pair<int, pair<int, int>> tmp[102][102];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        map[r][c] = {s, {d, z}};
    }
    int cnt = 0;
    for (int k = 1; k <= C; k++) {
        for (int i = 1; i <= R; i++) {
            if (map[i][k].second.first == 0) continue;
            else {
                map[i][k].second.first = 0;
                cnt += map[i][k].second.second;
                break;
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                int y = i;
                int x = j;
                int speed = map[i][j].first;
                int direct = map[i][j].second.first;
                int size = map[i][j].second.second;
                if (direct == 0) continue;
                switch (direct) {
                    case 1:
                        if ((y - speed) > 1) {
                            y = y - speed;
                        } else if ((y - speed) == 1) {
                            y = y - speed;
                            direct = 2;
                        } else {
                            int ny = speed + ((R - 1) - y);
                            if (ny / (R - 1) % 2 == 1) {
                                direct = 2;
                                y = ny % (R - 1) + 2;
                            } else {
                                y = (R - 1) - (ny % (R - 1));
                            }
                        }

                        if (tmp[y][x].second.second != 0) {
                            if (tmp[y][x].second.second < size) {
                                tmp[y][x] = {speed, {direct, size}};
                            }
                        } else {
                            tmp[y][x] = {speed, {direct, size}};
                        }
                        break;
                    case 2:
                        if ((y + speed) < R) {
                            y = y + speed;
                        } else if ((y + speed) == R) {
                            y = y + speed;
                            direct = 1;
                        } else {
                            int ny = speed + (R - (R - y + 1));
                            if (ny / (R - 1) % 2 == 1) {
                                direct = 1;
                                y = R - (ny % (R - 1));
                            } else {
                                y = (ny % (R - 1)) + 1;
                            }
                        }

                        if (tmp[y][x].second.second != 0) {
                            if (tmp[y][x].second.second < size) {
                                tmp[y][x] = {speed, {direct, size}};
                            }
                        } else {
                            tmp[y][x] = {speed, {direct, size}};
                        }
                        break;
                    case 3:
                        if ((x + speed) < C) {
                            x = x + speed;
                        } else if ((x + speed) == C) {
                            x = x + speed;
                            direct = 4;
                        } else {
                            int nx = speed + (C - (C - x + 1));
                            if (nx / (C - 1) % 2 == 1) {
                                direct = 4;
                                x = C - (nx % (C - 1));
                            } else {
                                x = (nx % (C - 1)) + 1;
                            }
                        }

                        if (tmp[y][x].second.second != 0) {
                            if (tmp[y][x].second.second < size) {
                                tmp[y][x] = {speed, {direct, size}};
                            }
                        } else {
                            tmp[y][x] = {speed, {direct, size}};
                        }
                        break;
                    case 4:
                        if ((x - speed) > 1) {
                            x = x - speed;
                        } else if ((x - speed) == 1) {
                            x = x - speed;
                            direct = 3;
                        } else {
                            int nx = speed + ((C - 1) - x);
                            if (nx / (C - 1) % 2 == 1) {
                                direct = 3;
                                x = nx % (C - 1) + 2;
                            } else {
                                x = (C - 1) - (nx % (C - 1));
                            }
                        }

                        if (tmp[y][x].second.second != 0) {
                            if (tmp[y][x].second.second < size) {
                                tmp[y][x] = {speed, {direct, size}};
                            }
                        } else {
                            tmp[y][x] = {speed, {direct, size}};
                        }
                        break;
                }
            }

        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                map[i][j] = tmp[i][j];
                //cout << map[i][j].second.second << " ";
            }
            //cout << endl;
        }
        memset(tmp, 0, sizeof(tmp));
        //cout << endl;
    }
    cout << cnt;
}