/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.2.6.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 17 Jun 2021 09:59:22 AM CST
*   Describe: 
*   
**************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 810;
const int maxm = 510;
const int INF = 1e8;
int mp[maxn][maxn], dis[maxn], cow[maxm];
bool vis[maxn];
int N, P, C;

int main() {
#ifdef Debug
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
#endif
    scanf("%d %d %d", &N, &P, &C);
    for(int i = 0; i < N; ++i) scanf("%d", cow + i);
    
    for(int i = 1; i <= P; ++i) {
        for(int j = 1; j <= P; ++j) if(i != j) mp[i][j] = INF;
    }

    for(int i = 0; i < C; ++i) {
        int A, B, D;
        scanf("%d %d %d", &A, &B, &D);
        mp[A][B] = D;
        mp[B][A] = D;
    }
    
    //for(int i = 1; i <= P; ++i) mp[i][i] = INF;
    
    for(int k = 1; k <= P; ++k) {
        for(int i = 1; i <= P; ++i) {
            for(int j = 1; j <= P; ++j) if(mp[i][j] > mp[i][k] + mp[k][j]) 
                mp[i][j] = mp[i][k] + mp[k][j];
        }
    }

    int ans = INF;
    for(int i = 1; i <= P; ++i) {
        int sum = 0;
        for(int j = 0; j < N; ++j) {
            sum += mp[i][cow[j]];
        }
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}

