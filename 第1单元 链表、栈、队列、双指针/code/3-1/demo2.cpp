#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int head, v[N], ne[N], idx;

void init(){
	head = -1, idx = 0;
}

void push_front(int x){
	v[idx] = x, ne[idx] = head, head = idx++;
}

void insert(int k, int x){
	v[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void del(int k){
	ne[k] = ne[ne[k]];
}

void traverse(){
	for(int i = head; ~i; i = ne[i]) cout << v[i] << " ";
	puts("");
}

int main() {

	init();
	push_front(1);
	push_front(3);
	push_front(5);
	push_front(8);

	insert(1, 99);

	del(3);

	traverse();
	
	return 0;
}

