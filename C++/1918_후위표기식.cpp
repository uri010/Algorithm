//
// Created by 김유리 on 2022/06/21.
//
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char value;
    Node* next;
    Node() {
        value = 0;
        next = NULL;
    }
};

class StackList {
public:
    Node* head;
    int stackSize;
    StackList() {
        head = NULL;
        stackSize = 0;
    }

    bool empty() {
        if (stackSize == 0)
            return true;
        else
            return false;
    }

    void push(char x) {
        Node* new_node = new Node;
        new_node->value = x;
        if (empty())
            head = new_node;
        else {
            new_node->next = head;
            head = new_node;
        }
        stackSize++;
    }

    void pop() {
        if (empty())
            cout << "Error" << endl;
        else {
            head = head->next;
            stackSize--;
        }
    }

    char top() {
        if (empty())
            return -1;
        else
            return head->value;
    }
};

int priority(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    string s;
    cin >> s;
    StackList stack;

    for (int i = 0; i < s.length(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(') {
                stack.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!stack.empty() && stack.top() != '(') {
                    cout << stack.top();
                    stack.pop();
                }
                stack.pop();
            }
            else {
                while (!stack.empty() && (priority(stack.top()) >= priority(s[i]))) {
                    cout << stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            }
        }
    }

    while (!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }

    return 0;
}