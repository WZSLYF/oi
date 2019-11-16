#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)
#define Rep1(i, s, e) for(int i = s; i <= e; ++i)

const int maxn = 1e4 + 10;
struct title {
    int P, T;
}dat[maxn];
int dp[maxn], N, M;

int main() {
    scanf("%d %d", &M, &N);

    Rep(i, N) scanf("%d %d", &dat[i].P, &dat[i].T);

    Rep(i, N) Rep1(j, dat[i].T, M) dp[j] = max(dp[j], dp[j - dat[i].T] + dat[i].P);

    int ans = 0;
    Rep(i, M + 1) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}
