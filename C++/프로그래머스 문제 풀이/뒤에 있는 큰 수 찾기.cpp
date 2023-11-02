//
// Created by 김유리 on 2023/11/02.
//
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stack;

    stack.push(numbers[numbers.size() - 1]);
    answer.push_back(-1);

    for (int i = numbers.size() - 2; i >= 0; i--) {
        int num = -1;

        while (!stack.empty()) {
            if (stack.top() > numbers[i]) {
                num = stack.top();
                break;
            } else {
                stack.pop();
            }
        }
        stack.push(numbers[i]);
        answer.push_back(num);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}