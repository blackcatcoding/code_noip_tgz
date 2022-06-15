#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;

int n;
int a[N], s[N];
int f[N][N], g[N][N];

int main() {
  
  	cin >> n;
  
  	for(int i = 1; i <= n; i++){
    	cin >> a[i];
      	a[i + n] += a[i];
    }
  
  	for(int i = 1; i <= n * 2; i++) s[i] = s[i - 1] + a[i];
  
  	memset(f, 0x3f, sizeof f);
  	memset(g, -0x3f, sizeof g);
  
  	for(int len = 1; len <= n; len++){
    	for(int i = 1; i + len - 1 <= n * 2; i++){
        	int j = i + len - 1;
          	if(len == 1) f[i][j] = g[i][j] = 0;
          	for(int k = i; k < j; k++){
              	f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
          		g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
  
  	int minv = INF, maxv = -INF;
  	for(int i = 1; i <= n; i++){
    	minv = min(minv, f[i][i + n - 1]);
      	maxv = max(maxv, g[i][i + n - 1]);
    }
  
  	cout << minv << endl << maxv << endl;
	
	return 0;
}


