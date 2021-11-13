/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 4281.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 08 Jul 2021 10:11:09 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
const int maxm = 31;
struct edge {
    int to, nxt;
}e[maxn << 1];
int head[maxn], fa[maxn][maxm], dep[maxn], lg[maxn], tot;


void addedge(int u, int v) {
    e[++tot].nxt = head[u];
    e[tot].to = v;
    head[u] = tot;
}

void dfs(int u, int  pa) {
    fa[u][0] = pa;
    dep[u] = dep[pa] + 1;
    for(int i = 1; i <= lg[dep[u]]; ++i)  fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v != pa) dfs(v, u);
    }
}

int Lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    while(dep[u] > dep[v]) u = fa[u][lg[dep[u] - dep[v]] - 1];
    if(u == v) return u;
    for(int i = lg[dep[u]] - 1; i >= 0; --i) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addedge(u, v), addedge(v, u);
    }
    //dfs(1, 0);
    for(int i = 1; i <= n; ++i) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(1, 0);
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        int res, ans;
        cin >> a >> b >> c;
        int t1 = Lca(a, b);
        int t2 = Lca(a, c);
        int t3 = Lca(b, c);
        if(t1 == t2) res = t3;
        else if(t1 == t3) res = t2;
        else if(t2 == t3) res = t1;
        ans = dep[a] + dep[b] + dep[c] - dep[t1] - dep[t2] - dep[t3];
        cout << res << " " << ans << endl;
    }
    return 0;
}

