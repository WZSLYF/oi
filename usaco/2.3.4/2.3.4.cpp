#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
const int maxm = 1e4 + 10;

int V, N, dat[maxn];
long long dp[maxm];

int main() {
    scanf("%d %d", &V, &N);
    for(int i = 0; i < V; ++i) scanf("%d", &dat[i]);

    dp[0] = 1;
    for(int i = 0; i < V; ++i) for(int j = dat[i]; j <= N; ++j) dp[j] += dp[j - dat[i]];
    printf("%lld\n", dp[N]);
    return 0;
}
