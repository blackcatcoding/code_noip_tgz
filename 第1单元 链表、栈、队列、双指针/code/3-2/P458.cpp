#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode* pNext;
}Node, * PNode;

class MyList {
private:
	PNode head, p;
public:
	MyList() {
		head = new Node;
		head->pNext = NULL;
		p = NULL;
	}

	void push_back(int x);
	void push_front(int x);

	void traverse();
};

MyList lst1, lst2;
int n, x;

int main() {

	while (cin >> n) {
		if (n == 0) {
			puts("list is empty");
			break;
		}
		for (int i = 1; i <= n; i++) {
			cin >> x;
			lst1.push_back(x);
			lst2.push_front(x);
			
		}
		lst1.traverse();
		lst2.traverse();
	}

	return 0;
}

void MyList::push_back(int x) {
	PNode s = new Node;
	s->data = x;
	s->pNext = NULL;

	if (head->pNext == NULL) {
		head->pNext = s;
		p = s;
	}
	else {
		p->pNext = s;
		p = s;
	}
}

void MyList::push_front(int x) {
	PNode s = new Node;
	s->data = x;
	s->pNext = NULL;
	if (head->pNext == NULL) {
		head->pNext = s;
		p = s;
	}
	else {
		s->pNext = head->pNext;
		head->pNext = s;
	}
}

void MyList::traverse() {
	PNode t = head->pNext;
	while (t) {
		cout << t->data << " ";
		t = t->pNext;
	}
	puts("");
}

