/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.4.2.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Sat 19 Jun 2021 12:16:04 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int n, m, p;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
#ifdef Debug
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &p);
    int s = p * m / 2;
    int b = gcd(n, m) + gcd(abs(n - p), m) + p;
    printf("%d\n", s - b / 2 + 1);
    return 0;
}

