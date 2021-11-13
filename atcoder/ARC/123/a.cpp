/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: a.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Sun 18 Jul 2021 08:59:57 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll A, B, C;

int main()
{
    cin >> A >> B >> C;
    B *= 2;
    if(B >= A + C) cout << B - (A + C) << endl;
    else {
        ll tmp = (A + C) - B;
        ll ans = tmp / 2;
        if(tmp % 2) ans += 2;
        cout << ans << endl;
    };
    return 0;
}

