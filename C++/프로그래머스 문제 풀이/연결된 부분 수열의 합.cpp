//
// Created by 김유리 on 2023/10/23.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long S[1000001];

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int length = sequence.size() + 1;
    int startAns = 0, endAns = 0;
    int sIdx = 0;
    int eIdx = 0;

    int sum = sequence[0];
    while (sIdx <= eIdx && eIdx < sequence.size()) {
        if (sum < k) {
            sum += sequence[++eIdx];
        } else if (sum > k) {
            sum -= sequence[sIdx++];
        } else {
            if (length > eIdx - sIdx + 1) {
                length = eIdx - sIdx + 1;
                startAns = sIdx;
                endAns = eIdx;
            } else if (length == eIdx - sIdx + 1) {
                if (startAns > sIdx) {
                    startAns = sIdx;
                    endAns = eIdx;
                }
            }
            sum -= sequence[sIdx++];
        }
    }
    answer.push_back(startAns);
    answer.push_back(endAns);

    return answer;
}