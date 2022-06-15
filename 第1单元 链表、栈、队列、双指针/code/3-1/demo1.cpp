#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

list<int> lst;

int main() {

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_front(5);
	lst.push_front(6);
	lst.push_front(7);
	lst.push_front(8);

	list<int>::iterator it = lst.begin();
	it++;
	it++;
	it++;
	lst.insert(it, 88);

	it++;
	it++;

	lst.erase(it);

	for(list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	
	return 0;
}

