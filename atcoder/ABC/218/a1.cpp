/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: a1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 一  9/13 03:01:22 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char str[8];
    scanf("%d %s", &n, str);
    if(str[n - 1] == 'o') puts("Yes");
    else puts("No");
    return 0;
}

