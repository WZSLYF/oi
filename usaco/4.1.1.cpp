/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 4.1.1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Tue 20 Jul 2021 06:16:28 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 11;
const int maxm = 67000;
int dat[maxn], N;
bool iscanget[maxm];

#define rep(i, a, b) for(register int i = a; i <= b; ++i)

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

//max: p, q gcd(p, q) = 1 -> max 不能表示的是p * q - p - q 不会证明 
int main()
{
    cin >> N;
    rep(i, 1, N) cin >> dat[i];
    int tmp = 0;
    rep(i, 1, N) tmp = gcd(tmp, dat[i]);
    if(tmp != 1) {
        cout << 0 << endl;
        return 0;
    }
    iscanget[0] = true;
    rep(i, 1, N) {
        rep(j, dat[i], maxm - 1) if(iscanget[j - dat[i]]) iscanget[j] = true;
    }
    
    int ans = 0;
    for(int i = maxm - 1; i >= 0; --i) if(!iscanget[i]) {
        //cout << i << endl;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}

