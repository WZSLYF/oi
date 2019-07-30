#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, k, dat[maxn];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", &dat[i]);

    int tmp = -1;
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if(i - 1 == tmp) continue;
        if(abs(dat[i] - dat[i - 1]) < k) ans++, tmp = i;
    }
    printf("%d\n", ans);
    return 0;
}
