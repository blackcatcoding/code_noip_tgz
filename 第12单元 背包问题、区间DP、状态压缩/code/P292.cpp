#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

const int M = 1 << 10;

int n, k;
LL f[12][110][M] = {1};

vector<int> states;	// 预处理所有合法状态 二进制中没有相邻的1
vector<int> h[M];

bool check(int x){
	return !(x & x >> 1);
}

int count(int x){
	int res = 0;
  	for(int i = 0; i < n; i++)
      	if(x >> i & 1) res++;
  
  	return res;
}

int main() {
  
  	cin >> n >> k;
  	for(int i = 0; i < 1 << n; i++)
      	if(check(i)) states.push_back(i);
  
  	for(int i = 0; i < states.size(); i++)
      	for(int j = 0; j < states.size(); j++){
        	int x = states[i], y = states[j];
          	if((x & y) == 0 && check(x | y))
              	h[i].push_back(j);
        }
  
  	for(int i = 1; i <= n + 1; i++)
      	for(int j = 0; j <= k; j++)
          	for(int a = 0; a < states.size(); a++)
              	for(int b : h[a]){
                	int t = count(states[a]);
                  	if(j >= t)
                      	f[i][j][a] += f[i - 1][j - t][b];
                }
  
  	cout << f[n + 1][k][0] << endl;
  
	return 0;
}

