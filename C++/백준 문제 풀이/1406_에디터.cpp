#include <iostream>
using namespace std;

class Node {
public:
	char data;
	Node* next;
	Node* prev;
	Node() {
		data = ' ';
		next = NULL;
		prev = NULL;
	}
};

class List {
public:
	Node* head;
	Node* tail;
	Node* cursor;
	int listSize;
	List() {
		head = new Node;
		tail = new Node;
		cursor = new Node;
		listSize = 0;
	}

	void push(char x) {
		Node* new_node = new Node;
		new_node->data = x;
		if (listSize==0 ) {
			head->next = new_node;
			new_node->prev = head;
			tail->prev = new_node;
			new_node->next = tail;
		}
		else {
			tail->prev->next = new_node;
			new_node->prev = tail->prev;
			tail->prev = new_node;
			new_node->next = tail;
		}
		listSize++;
	}

	void push_cursor() {
		cursor->data = '|';
		tail->prev->next = cursor;
		cursor->prev = tail->prev;
		tail->prev = cursor;
		cursor->next = tail;
		listSize++;
	}

	void cursor_L() {
		if (cursor->prev != head) {
			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;
			cursor->prev = cursor->prev->prev;
			cursor->next = cursor->prev->next;
			cursor->prev->next = cursor;
			cursor->next->prev = cursor;
		}
	}

	void cursor_D() {
		if (cursor->next != tail) {
			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;
			cursor->prev = cursor->next;
			cursor->next = cursor->next->next;
			cursor->prev->next = cursor;
			cursor->next->prev = cursor;
		}
	}

	void cursor_B() {
		if (cursor->prev != head) {
			cursor->prev->prev->next = cursor;
			cursor->prev = cursor->prev->prev;
			listSize--;
		}
	}

	void cursor_P(char x) {
		Node* new_node = new Node;
		new_node->data = x;
		cursor->prev->next = new_node;
		new_node->prev = cursor->prev;
		new_node->next = cursor;
		cursor->prev = new_node;
		listSize++;
	}
	
	void print() {
		Node* cur_node = head->next;
		while (cur_node != tail) {
			if (cur_node != cursor) {
				cout << cur_node->data;
			}
			cur_node = cur_node->next;
		}
	}

};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	List ll;
	string s; 
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		ll.push(s[i]);
	}
	ll.push_cursor();

	cin.clear();
	int M;
	cin >> M;
	string command;
	while (M--) {
		cin >> command;
		if (command == "P") {
			char x;
			cin >> x;
			ll.cursor_P(x);
		}
		else if (command == "L") {
			ll.cursor_L();
		}
		else if (command == "D") {
			ll.cursor_D();
		}
		else if (command == "B") {
			ll.cursor_B();
		}
	}

	ll.print();



}