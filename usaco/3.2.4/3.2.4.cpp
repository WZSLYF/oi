/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.2.4.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 16 Jun 2021 10:04:40 PM CST
*   Describe: 
*   
**************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 3;
int a[maxn], b[maxn], c[maxn], d[maxn];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool judge(int x, int y, int z, int &t) {
    if(x == 0 && y == 0 && z == 0) return false;
    int tmp1 = b[0] * x + c[0] * y + d[0] * z;
    int tmp2 = b[1] * x + c[1] * y + d[1] * z;
    int tmp3 = b[2] * x + c[2] * y + d[2] * z;
    int tmp = (tmp1 + tmp2 + tmp3) / (a[0] + a[1] + a[2]);
    if(tmp == 0) return false;
    /*int tmp = gcd(tmp1, tmp2);
    tmp = gcd(tmp, tmp3);*/
    //tmp1 /= tmp, tmp2 /= tmp, tmp3 /= tmp;
    bool flags = (tmp1 == a[0] * tmp && tmp2 == a[1] * tmp && tmp3 == a[2] * tmp);
    /*if(flags) {
        printf("%d %d %d %d\n", x, y, z, tmp);
    }*/
    t = tmp;
    return flags;
}

int main() {
    int sum = 0;
    for(int i = 0; i < 3; ++i) scanf("%d", a + i), sum += a[i];
    for(int i = 0; i < 3; ++i) scanf("%d", b + i);
    for(int i = 0; i < 3; ++i) scanf("%d", c + i);
    for(int i = 0; i < 3; ++i) scanf("%d", d + i);
    
    if(sum == 0) {
        printf("0 0 0 0\n");
        return 0;
    }

    bool flags = false;
    int Min = 310;
    int ans[maxn + 1];
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            for(int k = 0; k < 100; ++k) {
                int t = 0;
                if(judge(i, j, k, t) && Min > i + j + k) {
                    Min = i + j + k;
                    ans[0] = i, ans[1] = j, ans[2] = k, ans[3] = t;
                }
            }
        }
    }

    if(Min == 310) printf("NONE\n");
    else printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}



