/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.3.5.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Fri 18 Jun 2021 07:05:38 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int dat[maxn], sum[maxn], dp[maxn][maxn], n;

int main()
{
#ifdef Debug
    freopen("game1.in", "r", stdin);
    freopen("game2.out", "w", stdout);
#endif
    int i, j, tmp;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i) scanf("%d", &dat[i]), sum[i] = sum[i - 1] + dat[i], dp[i][i] = dat[i];

    for(i = n - 1; i; --i) {
        for(j = i + 1; j <= n; ++j)
            tmp = sum[j] - sum[i - 1], dp[i][j] = max(tmp - dp[i + 1][j], tmp - dp[i][j - 1]);
    }
    printf("%d %d\n", dp[1][n], sum[n] - dp[1][n]);
    return 0;
}

