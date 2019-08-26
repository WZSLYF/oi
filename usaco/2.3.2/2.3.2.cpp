#include <bits/stdc++.h>

using namespace std;

#define Rep(i, s, e) for(int i = s; i < e; ++i)

const int maxn = 110;
const int maxm = 210;
const int MOD = 9901;

int N, K, c;
int dp[maxn][maxm], tmp[maxn][maxm];

int main() {
    scanf("%d %d", &N, &K);

    dp[1][1] = 1;
    Rep(i, 2, K + 1) {
        for(int j = 1; j <= N; j += 2) {
            for(int k = 1; k <= j - 1 - k; k += 2) {
                if(k != j - 1 - k) c = 2; else c = 1;
                dp[i][j] += c * (tmp[i - 2][k] * dp[i - 1][j - 1 - k] + 
                                 dp[i - 1][k] * tmp[i - 2][j - 1 - k] + 
                                 dp[i - 1][k] * dp[i - 1][j - 1 - k]);
                dp[i][j] %= MOD;
            }
        }
        
        for(int j = 0; j <= N; ++j) {
            tmp[i - 1][j] += tmp[i - 2][j] + dp[i - 1][j];
            tmp[i - 1][j] %= MOD;
        }
    }

    printf("%d\n", dp[K][N]);
    return 0;
}
