/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.3.2.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 17 Jun 2021 04:24:30 PM CST
*   Describe: 
*   
**************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 6;
const int INF = 1e8;
int dp[maxn][maxn][maxn][maxn][maxn];
int s, b;

struct shop {
    int cnt;
    int mp[maxn];
    int num[maxn];
    int val;
};

vector<shop> vec;
map<int, int> mp;
int tot;
int ans[maxn];

int main() {
    //memset(dp, 0, sizeof(dp));
    //int siz = pow(1.0 * maxn, 5);
    //fill_n(dp, siz, (int)1e8);
    memset(dp, 1, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    scanf("%d", &s);
    for(int i = 1; i <= s; ++i) {
        shop p;
        scanf("%d", &p.cnt);
        for(int j = 0; j < p.cnt; ++j) {
            scanf("%d %d", &p.mp[j], &p.num[j]);
            if(!mp.count(p.mp[j])) mp[p.mp[j]] = ++tot;
        }
        scanf("%d", &p.val);
        vec.push_back(p);
    }

    scanf("%d", &b);
    for(int i = 1; i <= b; ++i) {
        shop p;
        p.cnt = 1;
        scanf("%d", &p.mp[0]);
        if(!mp.count(p.mp[0])) mp[p.mp[0]] = ++tot;
        scanf("%d %d", &ans[mp[p.mp[0]]], &p.val);
        p.num[0] = 1;
        vec.push_back(p);
    }

    for(int i = 0; i < (int)vec.size(); ++i) {
        int tmp[maxn];
        shop p = vec[i];
        memset(tmp, 0, sizeof(tmp));
        for(int j = 0; j < p.cnt; ++j) {
            int temp = mp[p.mp[j]];
            tmp[temp] = p.num[j];
        }

        for(int j = 0; j < maxn; ++j) {
            for(int k = 0; k < maxn; ++k) {
                for(int t = 0; t < maxn; ++t) {
                    for(int l = 0; l < maxn; ++l) {
                        for(int m = 0; m < maxn; ++m) {
                            if(j >= tmp[1] && k >= tmp[2] && t >= tmp[3] && l >= tmp[4] && m >= tmp[5]) {
                                dp[j][k][t][l][m] = min(dp[j][k][t][l][m], dp[j - tmp[1]][k - tmp[2]][t - tmp[3]][l - tmp[4]][m - tmp[5]] + p.val);
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", dp[ans[1]][ans[2]][ans[3]][ans[4]][ans[5]]);
    return 0;
}


