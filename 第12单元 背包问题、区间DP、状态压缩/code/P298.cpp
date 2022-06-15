#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 110, M = 1 << 10;

int n, m;
int g[N];
int f[2][M][M];
vector<int> states, h[M];

bool check(int x){
	return !(x & x >> 1 || x & x >> 2);
}

int count(int x){
	int res = 0;
  	for(int i = 0; i < m; i++)
      	if(x >> i & 1) res++;
  
  	return res;
}

int main() {
  
  	cin >> n >> m;
  	for(int i = 1; i <= n; i++)
      	for(int j = 0; j < m; j++){
        	char ch;
          	cin >> ch;
          	if(ch == 'H') g[i] += 1 << j;
        }
  
  	for(int i = 0; i < 1 << m; i++)
      	if(check(i)) states.push_back(i);
  
  	for(auto x : states)
      	for(auto y : states)
          	if((x & y) == 0) h[x].push_back(y);
  
  	for(int i = 1; i <= n + 2; i++)
      	for(auto s : states)
          	if(!(g[i] & s))
              	for(auto x : h[s])
                  	for(auto y: h[x])
                      	if(!(s & y))
                          	f[i & 1][s][x] = max(f[i & 1][s][x], f[i - 1 & 1][x][y] + count(s));
  
  	cout << f[n + 2 & 1][0][0] << endl;

	return 0;
}

