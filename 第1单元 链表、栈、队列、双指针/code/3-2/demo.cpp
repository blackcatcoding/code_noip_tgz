#include <iostream>
#include <cstdio>
using namespace std;

typedef struct ListNode{
	int data;
	ListNode* pNext;
}Node, *PNode;

class MyList{
private:
	PNode head, p;
public:
	MyList();

	void push_back(int x);
	void push_front(int x);

	void traverse();
};

int main() {

	MyList lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	lst.push_front(5);
	lst.push_front(6);
	lst.push_front(8);
	lst.push_front(9);

	lst.traverse();
	
	return 0;
}

MyList::MyList(){
	head = new Node;
	head->pNext = NULL;
	p = NULL;
}

void MyList::push_back(int x){
	PNode s = new Node;
	s->data = x;
	s->pNext = NULL;

	if(head->pNext == NULL){
		head->pNext = s;
		p = s;
	}
	else{
		p->pNext = s;
		p = s;
	}
}

void MyList::push_front(int x){
	PNode s = new Node;
	s->data = x;
	s->pNext = NULL;
	if(head->pNext == NULL){
		head->pNext = s;
		p = s;
	}
	else{
		s->pNext = head->pNext;
		head->pNext = s;
	}
}

void MyList::traverse(){
	PNode t = head->pNext;
	while(t){
		cout << t->data << " ";
		t = t->pNext;
	}
	puts("");
}
