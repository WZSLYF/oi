/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3478.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月28日 星期一 00时57分06秒
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e6 + 10;
struct edge {
    int nxt, to;
}e[maxn << 1];
int n, tot, res;
int head[maxn];
ll ans;
ll dp[maxn];
int dep[maxn], siz[maxn];

inline void addedge(int u, int v) {
    e[++tot].nxt = head[u];
    e[tot].to = v;
    head[u] = tot;
}

void dfs1(int u, int fa) {
    siz[u] = 1;
    dep[u] = dep[fa] + 1;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v != fa) {
            dfs1(v, u);
            siz[u] += siz[v];
        }
    }
}

void dfs2(int u, int fa) {
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v != fa) {
            dp[v] = dp[u] + n - 2 * siz[v];
            dfs2(v, u);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int u, v;
    int i;
    cin >> n;
    for(i = 1; i < n; ++i) {
        cin >> u >> v;
        addedge(u, v), addedge(v, u);
    }
    dfs1(1, 0);
    //cout << "dfs1 finish" << endl;
    for(i = 1; i <= n; ++i) dp[1] += dep[i];
    dfs2(1, 0);
    for(i = 1; i <= n; ++i) if(ans < dp[i]) ans = dp[i], res = i;
    cout << res << endl;
    return 0;
}

