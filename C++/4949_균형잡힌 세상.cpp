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
	void init() {
		head = NULL;
		stackSize = 0;
	}

	void push(char x) {
		Node* new_node = new Node;
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

	void pop() {
		if (stackSize != 0) {
			head = head->next;
			stackSize--;
		}
	}

	char top() {
		return head->data;
	}

	int size() {
		return stackSize;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int stringSize = 0;
	Stack stack;
	while (true) {
		string str;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '.') {
				if (stack.size() != 0) {
					stack.init();
					stringSize = 0;
					cout << "no" << "\n";
				}
				else if (stringSize != 0 && stack.size() == 0) {
					stack.init();
					stringSize = 0;
					cout << "yes" << "\n";
				}
				else if( stringSize ==0 && stack.size() ==0 ) {
					return 0;
				}
			}
			else if (str[i] == '(' || str[i] == '[') {
				stack.push(str[i]);
				stringSize++;
			}
			else if (str[i] == ')') {
				if (stack.size() !=0 && stack.top() == '(') {
					stack.pop();
				}
				else {
					stack.push(str[i]);
					stringSize++;
				}
			}
			else if (str[i] == ']') {
				if (stack.size() != 0 && stack.top() == '[') {
					stack.pop();
				}
				else {
					stack.push(str[i]);
					stringSize++;
				}
			}
			else {
				stringSize++;
			}
		}
	}
}