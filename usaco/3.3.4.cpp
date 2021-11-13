/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.3.4.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Fri 18 Jun 2021 06:11:38 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 255;
int dp[maxn][maxn]; //dp[i][j] 表示以i，j为右下角的最大正方形的边长（换个角度理解是i，j可以向左或向上延伸最长为1距离)
char mp[maxn][maxn];
int ans[maxn];
int n;

int main()
{
#ifdef Debug
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
#endif
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) scanf("%s", mp[i]);

    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) 
            if(mp[i][j] == '1') 
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1, ans[dp[i][j]]++;
    }

    for(i = n - 1; i; --i) ans[i] += ans[i + 1]; 
    //这里的话，考虑一下i， j这里最大边长k ->  k + 1了，少计算了以i，j为右下角，边长为k的这个正方形了，同理也少计算了i，j右下角，边长为k + 2的正方形
    for(i = 2; i <= n; ++i) if(ans[i]) printf("%d %d\n", i, ans[i]);
    return 0;
}

