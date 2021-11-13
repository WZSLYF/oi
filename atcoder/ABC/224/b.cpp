/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: b.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 三 10/27 01:14:27 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;
int dat[maxn][maxn], n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> dat[i][j];

    for(int t1 = 0; t1 < n; ++t1) for(int t2 = 0; t2 < m; ++t2) {
        for(int t3 = t1 + 1; t3 < n; ++t3) for(int t4 = t2 + 1; t4 < m; ++t4) {
            if(dat[t1][t2] + dat[t3][t4] > dat[t3][t2] + dat[t1][t4]) { cout << "No" << endl; return 0; }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

