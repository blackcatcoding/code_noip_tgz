#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int ans = 0;

bool check(int L, int R){
	bool h[N] = {};
  	for(int i = L; i <= R; i++){
    	if(h[a[i]]) return false;
      	h[a[i]] = true;
    }
  	return true;
}

int main() {
  
  	cin >> n;
  	for(int i = 1; i <= n; i++) cin >> a[i];
      
  	for(int i = 1; i <= n; i++){
    	for(int j = i; j <= n; j++){
        	if(check(i, j)) ans = max(ans, j - i + 1);
        }
    }
  
  	cout << ans << endl;

	return 0;
}
