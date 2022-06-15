#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 310;

int n;
int s[N];
int f[N][N];

int main() {
  
  	cin >> n;
  
  	for(int i = 1; i <= n; i++){
    	cin >> s[i];
      	s[i] += s[i - 1];
    }
  
  	memset(f, 0x3f, sizeof f);
  
  	for(int len = 1; len <= n; len++){
    	for(int i = 1; i + len - 1 <= n; i++){
        	int j = i + len - 1;
          	if(len == 1) f[i][j] = 0;
          	for(int k = i; k < j; k++)
              	f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }
    }
  
  	cout << f[1][n] << endl;
	
	return 0;
}


