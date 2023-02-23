//
// Created by 김유리 on 2022/12/19.
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<long long> pq_min;
priority_queue<long long> pq_max;
map<long long, int> m;

int t, k;
char c;
long long num;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        while( !pq_min.empty()) pq_min.pop();
        while( !pq_max.empty()) pq_max.pop();
        m.clear();
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> c >> num;
            switch (c) {
                case 'I':
                    m[num]++;
                    pq_min.push(-num);
                    pq_max.push(num);
                    break;
                case 'D':
                    if (num == -1) {
                        while (!pq_min.empty() && m[-pq_min.top()] == 0) pq_min.pop();
                        if (pq_min.empty()) continue;
                        m[-pq_min.top()]--;
                        pq_min.pop();
                    } else if (num == 1) {
                        while (!pq_max.empty() && m[pq_max.top()] == 0) pq_max.pop();
                        if (pq_max.empty()) continue;
                        m[pq_max.top()]--;
                        pq_max.pop();
                    }
                    break;
            }
            while (!pq_min.empty() && m[-pq_min.top()] == 0) pq_min.pop();
            while (!pq_max.empty() && m[pq_max.top()] == 0) pq_max.pop();
        }
        if (!pq_min.empty() && !pq_max.empty())
            cout << pq_max.top() << " " << -pq_min.top() << "\n";
        else cout << "EMPTY\n";
    }
}