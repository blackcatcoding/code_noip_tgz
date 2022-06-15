#include <iostream>
#include <cstdio>
#include <string>
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

MyList lst;
int n, m;
string op;
int k, x;

int main() {

	
  	cin >> n;
  	while(n--){
    	cin >> x;
      	lst.push_front(x); 
    }	
  
  	cin >> m;
  	while(m--){
    	
      	cin >> op;
      	if(op == "show"){
        	if(lst.size() > 0) lst.traverse();
          	else puts("Link list is empty");
        }
      	else if(op == "insert"){
        	cin >> k >> x;
          	if(k <= lst.size() || (lst.size() == 0 && k == 1)){
            	lst.insert(k, x);
              	puts("insert OK");
            }
          	else puts("insert fail");
        }
      	else if(op == "get"){
        	cin >> k;
          	if(k <= lst.size()) cout << lst.get(k) << endl;
          	else puts("get fail");
        }
      	else if(op == "delete"){
        	cin >> k;
          	if(k <= lst.size()){
            	lst.del(k);
              	puts("delete OK");
            }
          	else puts("delete fail");
        }
      	
    }
	
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