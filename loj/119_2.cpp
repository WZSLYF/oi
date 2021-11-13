/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 119_2.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 08 Jul 2021 11:29:10 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2510;
const int maxm = 6210;
struct edge {
    int to, val, nxt;
}e[maxm << 1];
int head[maxn], tot;
int dis[maxn];
bool vis[maxn];
int n, m, s, t;
queue<int> que;

void addedge(int u, int v, int val) {
    e[++tot].to = v;
    e[tot].val = val;
    e[tot].nxt = head[u];
    head[u] = tot;
}

void spfa() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0, vis[s] = 1;
    que.push(s);
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 0;
        for(int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to, z = e[i].val;
            if(dis[y] > dis[x] + z) {
                dis[y] = dis[x] + z;
                if(!vis[y]) que.push(y), vis[y] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; ++i) {
        int u, v, val;
        cin >> u >> v >> val;
        addedge(u, v, val);
        addedge(v, u, val);
    }
    spfa();
    cout << dis[t] << endl;
    return 0;
}

