/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: a.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 一  9/13 02:50:22 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string str;
    cin >> n >> str;
    if(str[n - 1] == 'o') printf("Yes\n");
    else printf("No\n");
    return 0;
}

