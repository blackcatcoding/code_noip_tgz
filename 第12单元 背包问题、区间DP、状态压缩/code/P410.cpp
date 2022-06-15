#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;
int n, m, k;
int f[N][N];

int main() {

    scanf("%d%d%d", &n, &m, &k);
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;

    while(k--){
        int v1, v2, w;
        scanf("%d%d%d", &v1, &v2, &w);

        for(int i = n; i >= 0; i--)
            for(int j = m; j >= 0; j--)
                f[i][j] = min(f[i][j], f[max(0, i - v1)][max(0, j - v2)] + w);
    }
    
    printf("%d\n", f[n][m]);
	return 0;
}
