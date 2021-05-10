#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n;
long long f[maxn][2], dat[maxn][2];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%I64d", &dat[i][0]);
    for(int i = 0; i < n; ++i) scanf("%I64d", &dat[i][1]);

    f[0][0] = dat[0][0];
    f[0][1] = dat[0][1];
    
    long long ans = max(dat[0][0], dat[0][1]);
    for(int i = 1; i < n; ++i) {
	f[i][0] = max(dat[i][0], f[i - 1][0]);
	f[i][1] = max(dat[i][1], f[i - 1][1]);
        f[i][1] = max(f[i][1], f[i - 1][0] + dat[i][1]);
        f[i][0] = max(f[i][0], f[i - 1][1] + dat[i][0]);
        ans = max(ans, f[i][0]);
        ans = max(ans, f[i][1]);
    }
    printf("%I64d\n", ans);
    return 0;
}
