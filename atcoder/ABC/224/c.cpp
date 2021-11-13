/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 六 10/30 00:13:01 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for(auto &r:p) { cin >> r.first >> r.second; }
    int res = 0;
    for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) for(int k = j + 1; k < n; ++k) {
        if((p[j].second - p[i].second) * (p[k].first - p[j].first) - (p[j].first - p[i].first) * (p[k].second - p[j].second) != 0) res++;
    }
    cout << res << endl;
    return 0;
}

