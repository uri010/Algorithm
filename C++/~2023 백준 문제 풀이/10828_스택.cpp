#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node() {
		value = 0;
		next = NULL;
	}
};

class Stack {
public:
	Node* head;
	int stackSize;

	Stack() {
		head = NULL;
		stackSize = 0;
	}

	void push(int x) {
		Node* new_node = new Node;
		new_node->value = x;
		if (empty()) {
			head = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		stackSize++;
	}

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			int tmp = head->value;
			head = head->next;
			stackSize--;
			cout << tmp << "\n";
		}
	}

	void size() {
		cout << stackSize << "\n";
	}

	bool empty() {
		if (stackSize == 0) {
			return 1;
		}
		else return 0;
	}

	void top() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << head->value << "\n";
		}
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string str;
	Stack stack;

	while (N--) {
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			stack.push(x);
		}
		else if (str == "pop") {
			stack.pop();
		}
		else if (str == "size") {
			stack.size();
		}
		else if (str == "empty") {
			if (stack.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "top") {
			stack.top();
		}
		else {
			cout << "Wrong Command" << "\n";
		}

	}
}

