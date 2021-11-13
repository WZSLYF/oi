/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.2.3.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 16 Jun 2021 06:21:30 PM CST
*   Describe: 
*   
**************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//#define Debug

const int maxn = 5;
const int maxm = 360;
int sped[maxn + 1], whst[maxn + 1][maxn + 1], whwd[maxn + 1][maxn + 1], w[maxn + 1], pos[maxn + 1];
int light[maxm];

void mark(int ind) {
    int wpos;
    for(int i = 1; i <= w[ind]; ++i) {
        wpos = (pos[ind] + whst[ind][i]) % maxm;
        for(int j = 0; j <= whwd[ind][i]; ++j) light[wpos]++, wpos = (wpos + 1) % maxm;
    }
}

int main() {
#ifdef Debug
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
#endif
    for(int i = 1; i <= maxn; ++i) {
        scanf("%d %d", &sped[i], &w[i]);
        for(int j = 1; j <= w[i]; ++j) scanf("%d %d", &whst[i][j], &whwd[i][j]);
    }
    
    int t = 0;
    while(t < 360) {
        memset(light, 0, sizeof(light));

        for(int i = 1; i <= maxn; ++i) {
            mark(i);
        }
        
        bool flags = false;
        for(int i = 0; i < maxm; ++i) if(light[i] == 5) {
            flags = true;
            break;
        }

        if(flags) break;

        for(int i = 1; i <= maxn; ++i)
            pos[i] = (pos[i] + sped[i]) % maxm;

        ++t;
    }

    if(t == 360) printf("none\n");
    else printf("%d\n", t);
    return 0;
}



