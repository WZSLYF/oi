/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: d1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 六  9/25 20:50:25 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pr pair<int, int>

struct cmp {
    bool operator() (pr &a, pr &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), cmp());
    ll ans = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        if(v[i].first < v[j].first && v[i].second < v[j].second) {
            if(binary_search(v.begin(), v.end(), make_pair(v[i].first, v[j].second)) && 
               binary_search(v.begin(), v.end(), make_pair(v[j].first, v[i].second))) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

