#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> PII;

struct Node{
	int t1, t2;
	bool operator< (const Node& x) const{
		return t1 < x.t1;
	}
};

int n, m1, m2;

// q1国内航班廊桥, q2国际航班廊桥
vector<Node> q1, q2;

int ans1[N], ans2[N];
int answer = 0;

void work(vector<Node>& q, int m, int ans[]){
	priority_queue<PII, vector<PII>, greater<PII> > usedQ;
  	priority_queue<int, vector<int>, greater<int> > freeQ;
  	
  	for(int i = 1; i <= m; i++) freeQ.push(i);
  
  	for(int i = 0; i < m; i++){
    	while(!usedQ.empty() && q[i].t1 > usedQ.top().first){
        	freeQ.push(usedQ.top().second);
          	usedQ.pop();
        }
      	if(!freeQ.empty()){
        	int smallestnum = freeQ.top();
          	usedQ.push({q[i].t2, smallestnum});
          	freeQ.pop();
          	ans[smallestnum]++;
        }
    }
  
  	// for(int i = 1; i <= n; i++) cout << ans[i] << " ";
  	// cout << endl;
  	for(int i = 1; i <= n; i++) ans[i] += ans[i - 1];
}

int main(){
	// n廊桥数量 m1国内航班数量 m2国际航班数量
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= m1; i++){
		int t1, t2;
		cin >> t1 >> t2;
		q1.push_back({t1, t2});
	}

	for(int i = 1; i <= m2; i++){
		int t1, t2;
		cin >> t1 >> t2;
		q2.push_back({t1, t2});
	}

	sort(q1.begin(), q1.end(), less<Node>());
	sort(q2.begin(), q2.end(), less<Node>());
	
	work(q1, m1, ans1);
  	work(q2, m2, ans2);
  
  	for(int i = 0; i <= n; i++)
      	answer = max(answer, ans1[i] + ans2[n - i]);

	cout << answer << endl;

	return 0;
}

