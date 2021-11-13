/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: d.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 六  9/25 20:05:50 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2010;
int x[maxn], y[maxn], n;

struct node {
    int x, y;
    bool operator <(const node &b) const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
};

map<node, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        mp[(node){x[i], y[i]}] = 1;
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(x[i] == x[j] || y[i] == y[j]) continue;
            if(mp[(node){x[i], y[j]}] == 1 && mp[(node){x[j], y[i]}] == 1) ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}

