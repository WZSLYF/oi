#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;
int n;
long long ans[maxn];

int main() {
    scanf("%d", &n);
    
    ans[0] = 1;
    int tmp = (1 + n) * n / 2;
    if(tmp & 1) {
        printf("0\n");
	return 0;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = tmp; j > 0; --j) if(j >= i) ans[j] += ans[j - i];
    }
    
    printf("%lld\n", ans[tmp/2] / 2);
    return 0;
}

