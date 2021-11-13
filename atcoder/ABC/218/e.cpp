/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: e.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 六  9/25 22:59:43 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> fa, sz;

    dsu(int n) : fa(n), sz(n) {
        iota(fa.begin(), fa.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int Find(int x) {
        return x == fa[x] ? x : fa[x] = Find(fa[x]);
    }

    void Union(int x, int y) {
        assert(x >= 0);
        assert(y >= 0);
        x = Find(x), y = Find(y);
        if(x == y) {
            return;
        }
        
        //cout << x << y << endl;
        if(sz[x] < sz[y]) {
            swap(x, y);
        }

        sz[x] += sz[y];
        fa[y] = x;
    }

    int Size(int x) {
        return x == fa[x] ? sz[x] : sz[x] = sz[Find(x)];
    }

    bool Diff(int x, int y) {
        return Find(x) != Find(y);
    }
};

struct node {
    int u, v, w;
    node() {}
    node(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};

struct cmp {
    bool operator () (const node &a, const node &b) {
        return a.w < b.w;
    }
};

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<node> edge(m);
    ll ans = 0;
    for(auto& iter : edge) {
        cin >> iter.u >> iter.v >> iter.w;
        --iter.u, --iter.v;
        if(iter.w >= 0) ans += iter.w;
    }

    sort(edge.begin(), edge.end(), cmp());
    
    //cout << "here" << endl;
    dsu ds(n);
    for(auto& iter : edge) {
        //cout << iter.u << iter.v << endl;
        if(ds.Diff(iter.u, iter.v)) {
            ds.Union(iter.u, iter.v);
            if(iter.w >= 0) ans -= iter.w;
        }
    }

    cout << ans << endl;
    return 0;
}

