/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3379.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月28日 星期一 16时21分35秒
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
const int maxm = 31;
int fa[maxn][maxm], dep[maxn], lg[maxn];
int head[maxn], tot;
struct edge{
    int to, nxt;
}e[maxn << 1];

void add(int x, int y) {
    e[++tot].to = y;
    e[tot].nxt = head[x];
    head[x] = tot;
}

void dfs(int now, int pa) {
    fa[now][0] = pa;
    dep[now] = dep[pa] + 1;
    for(int i = 1; i <= lg[dep[now]]; ++i) fa[now][i] = fa[fa[now][i - 1]][i - 1];
    for(int i = head[now]; i; i = e[i].nxt) if(e[i].to != pa) dfs(e[i].to, now);
}

int Lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
    if(x == y) return x;
    for(int k = lg[dep[x]] - 1; k >= 0; --k) {
        if(fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
    }
    return fa[x][0];
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= n; ++i) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(s, 0);
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        cout << Lca(x, y) << endl;
    }
    return 0;
}

