/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 119.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 08 Jul 2021 10:55:09 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2510;
int mp[maxn][maxn], dis[maxn];
bool vis[maxn];
int n, m, s, t;

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    for(int i = 1; i <= n; ++i) {
        int x = 0;
        for(int j = 1; j <= n; ++j) if(!vis[j] && (x == 0 || dis[j] < dis[x])) x = j;
        vis[x] = 1;
        for(int j = 1; j <= n; ++j) dis[j] = min(dis[j], dis[x] + mp[x][j]);
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    memset(mp, 0x3f, sizeof(mp));
    for(int i = 1; i <= n; ++i) mp[i][i] = 0;
    for(int i = 1; i <= m; ++i) {
        int u, v, val;
        cin >> u >> v >> val;
        mp[u][v] = min(mp[u][v], val);
        mp[v][u] = min(mp[v][u], val);
    }
    dijkstra();
    cout << dis[t] << endl;
    return 0;
}

