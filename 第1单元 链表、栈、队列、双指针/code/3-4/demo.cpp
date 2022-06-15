#include <iostream>
#include <cstdio>
using namespace std;

typedef struct ListNode{
	int data;
	ListNode* next;
	ListNode* prior;
}Node, *PNode;

class MyList{
private:
	PNode head, tail;
	int cnt = 0;

	PNode get_addr(int k);

public:
	MyList();

	int size();

	void push_back(int x);
	void push_front(int x);
	void insert(int k, int x);

	int get(int k);

	void del(int k);

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
	lst.push_front(7);
	lst.push_front(8);
	lst.insert(3, 666);
	lst.del(9);
	lst.traverse();
	
	return 0;
}

MyList::MyList(){
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prior = head;
	cnt = 0;
}

int MyList::size(){
	return cnt;
}

void MyList::insert(int k, int x){
	cnt++;
	PNode s = new Node;
	s->data = x;

	PNode p = get_addr(k);
	PNode q = p->prior;

	s->next = p;
	q->next = s;

	p->prior = s;
	s->prior = q;
}

void MyList::del(int k){
	PNode s = get_addr(k);
	PNode q = s->prior, p = s->next;
	p->prior = q;
	q->next = p;

	delete s;
	cnt--;
}

int MyList::get(int k){
	return get_addr(k)->data;
}

PNode MyList::get_addr(int k){
	if(k > size() || k <= 0) return NULL;

	PNode p = head->next;

	while(k > 1){
		p = p->next;
		k--;
	}

	return p;
}



void MyList::push_back(int x){
	cnt++;
	PNode s = new Node;
	PNode q = tail->prior;

	s->data = x;

	s->next = tail;
	q->next = s;
	tail->prior = s;
	s->prior = q;
}

void MyList::push_front(int x){
	cnt++;
	PNode s = new Node;
	PNode p = head->next;

	s->data = x;
	s->next = p;
	head->next = s;
	p->prior = s;
	s->prior = head;
}

void MyList::traverse(){
	PNode p = head->next;
	while(p != tail){
		cout << p->data << " ";
		p = p->next;
	}
	puts("");
}