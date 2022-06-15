#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n;
int h[N], cnt = 0;

void up(int u){
	while(u / 2 && h[u / 2] > h[u]){
    	swap(h[u / 2], h[u]);
      	u /= 2;
    }
}

void down(int u){
	int t = u;
  	if(u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
  	if(u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
  	if(u != t){
    	swap(h[u], h[t]);
      	down(t);
    }
}

int main() {
  
  	cin >> n;
  	for(int i = 1; i <= n; i++){
    	int x;
      	cin >> x;
      	h[++cnt] = x;
      	up(cnt);
    }
  
  	while(n--){
    	cout << h[1] << " ";
      	h[1] = h[cnt--];
      	down(1);
    }

	return 0;
}
