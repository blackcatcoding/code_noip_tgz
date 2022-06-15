#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int N = 1e6 + 10;

string s = "0", p = "0";
int ne[N];

int main() {
  
  	string t1, t2;
  	cin >> t1 >> t2;
  	s += t1, p += t2;
  
  	int plen = p.size();
  	for(int i = 2, j = 0; i < plen; i++){
    	while(j && p[i] != p[j + 1]) j = ne[j];
      	if(p[i] == p[j + 1]) j++;
      	ne[i] = j;
    }
  
  	while(true){
    	bool flag = false;
      	for(int i = 1, j = 0; i < s.size(); i++){
        	while(j && s[i] != p[j + 1]) j = ne[j];
          	if(s[i] == p[j + 1]) j++;
          	if(j == plen - 1){
            	int k = i - j + 1;
              	s.erase(s.begin() + k, s.begin() + i + 1);
              	flag = true;
              	break;
            }
        }
      	if(!flag) break;
    }
  
  	for(int i = 1; i < s.size(); i++) cout << s[i];

	return 0;
}
