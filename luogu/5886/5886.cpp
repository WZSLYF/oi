#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)

const int maxn = 1e6 + 10;
int n, m, p, k;
int dat[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &p);

    Rep(i, n) {
        scanf("%d", &k);
        int mk;
        Rep(j, k) scanf("%d", &mk), dat[mk-1]++;
    }
    
    int ans = 0;
    Rep(i, m) if(dat[i] == p) ans++;
    printf("%d\n", ans);
    int num = 0;
    Rep(i, m) if(dat[i] == p) {
        if(num) printf(" ");
        printf("%d", i + 1);
        num++;
    }
    printf("\n");
    return 0;
}
