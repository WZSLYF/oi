/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: b.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 一  9/13 03:04:47 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 26;
int dat[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a;
    for(int i = 0; i < maxn; ++i) {
        cin >> a;
        cout << (char)('a' + a - 1);
    }
    cout << endl;
    return 0;
}

