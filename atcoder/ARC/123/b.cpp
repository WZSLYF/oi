/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: b.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Sun 18 Jul 2021 09:15:18 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int datA[maxn], datB[maxn], datC[maxn];
int N;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> datA[i];
    for(int i = 1; i <= N; ++i) cin >> datB[i];
    for(int i = 1; i <= N; ++i) cin >> datC[i];

    sort(datA + 1, datA + 1 + N);
    sort(datB + 1, datB + 1 + N);
    sort(datC + 1, datC + 1 + N);

    int p = 1, q = 1, t = 1;
    int ans = 0;
    while(1) {
        while(q <= N && datB[q] <= datA[p]) ++q;
        if(q > N) break;
        while(t <= N && datC[t] <= datB[q]) ++t;
        if(t > N) break;
        ans++;
        p++, q++, t++;
    }
    cout << ans << endl;
    return 0;
}
