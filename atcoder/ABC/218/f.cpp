/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: f.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 一 10/ 4 18:13:42 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(n, maxn));
    vector<int> u(m), v(m);
    
    for(int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
        edge[u[i]][v[i]] = 1;
    }

    vector<int> dis(n), pre(n, -1);

    auto Dijkstra = [&]() {
        fill(dis.begin(), dis.end(), maxn);
        dis[0] = 0;
        queue<int> que;
        que.push(0);
        vector<bool> vis(n);
        vis[0] = true;
        while(not que.empty()) {
            int u = que.front();
            que.pop();
            for(int v = 0; v < n; ++v) {
                if(not vis[v] and dis[u] + edge[u][v] < dis[v]) {
                    dis[v] = dis[u] + edge[u][v];
                    vis[v] = true;
                    pre[v] = u;
                    que.push(v);
                }
            }
        }
    };

    Dijkstra();
    
    vector<vector<bool>> used(n, vector<bool>(n));
    for(int u = pre[n - 1], v = n - 1; u != -1; v = u, u = pre[u]) {
        used[u][v] = true;
    }

    for(int i = 0; i < m; ++i) {
        if(used[u[i]][v[i]]) {
            edge[u[i]][v[i]] = maxn;
            Dijkstra();
            cout << (dis[n - 1] == maxn ? -1 : dis[n - 1]) << endl;
            edge[u[i]][v[i]] = 1;
            Dijkstra();
        }
        else {
            cout << (dis[n - 1] == maxn ? -1 : dis[n - 1]) << endl;
        }
    }
    return 0;
}

