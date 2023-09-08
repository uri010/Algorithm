//
// Created by 김유리 on 2023/09/08.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v(10000001);

    for (int i = 0; i < tangerine.size(); i++) {
        v[tangerine[i]]++;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (k == 0) return answer;
        if (v[i] >= k) return answer + 1;
        k -= v[i];
        answer++;
    }
    return answer;
}