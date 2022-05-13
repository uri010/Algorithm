#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	char data;
	Node* next;
	Node() {
		data = ' ';
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

	void push(char x) {
		Node* new_node = new Node();
		new_node->data = x;
		if (stackSize == 0) {
			head = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		stackSize++;
	}

	char pop() {
		if (stackSize == 0) {
			cout << -1 << "\n";
		}
		else {
			char tmp = head->data;
			head = head->next;
			stackSize--;
			return tmp;
		}
	}

	int size() {
		return stackSize;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cin.ignore();
	while (N--) {
		Stack stack;
		string str;
		getline(cin, str);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				int stackSize = stack.size();
				for (int j = 0; j < stackSize; j++) {
					cout << stack.pop();
				}
				cout << " ";
			}
			else if (i == str.length() - 1) {
				stack.push(str[i]);
				int stackSize = stack.size();
				for (int j = 0; j < stackSize; j++) {
					cout << stack.pop();
				}
			}
			else {
				stack.push(str[i]);
			}
		}
		cout << "\n";
	}
}