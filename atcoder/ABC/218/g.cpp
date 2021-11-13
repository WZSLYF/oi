/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: g.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 二 10/ 5 08:28:32 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct kth_mutiset {
    multiset<int> mst1, mst2;

    void balance() {
        if(mst2.size()) {
            mst1.insert(*mst2.begin());
            mst2.erase(mst2.begin());
        }
        while(mst1.size() > mst2.size()) {
            mst2.insert(*mst1.rbegin());
            mst1.erase(prev(mst1.end()));
        }
    }

    void insert(int val) {
        mst2.insert(val);
        balance();
    }

    void erase(int val) {
        if(mst2.find(val) != mst2.end()) {
            mst2.erase(mst2.find(val));
        }
        else {
            mst1.erase(mst1.find(val));
        }
        balance();
    }

    int find_kth() {
        if(mst2.size() == mst1.size() + 1) {
            return *mst2.begin();
        }
        else {
            return (*mst1.rbegin() + *mst2.begin()) / 2;
        }
    }
}K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> G(n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dp(n);
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        K.insert(a[u]);
        int mi = 2e9, mx = 0;
        for(auto v : G[u]) {
            if(v != p) {
                dfs(v, u, d + 1);
                mi = min(mi, dp[v]), mx = max(mx, dp[v]);
            }
        }

        if(0 == mx) dp[u] = K.find_kth();
        else dp[u] = d & 1 ? mi : mx;
        K.erase(a[u]);
    };

    dfs(0, -1, 0);
    cout << dp[0] << endl;
    return 0;
}

