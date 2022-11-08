/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: 104.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Tue Nov  8 15:34:13 2022
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

#if __cplusplus >= 201703L
    #define REGISTER
    #define null  nullptr
#elif __cplusplus >= 201103L
    #define REGISTER register
    #define null  nullptr
#elif __cplusplus >= 199711L
    #define REGISTER register
    #define null  NULL
#endif

/* #pragma GCC target("avx2") */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC optimize("unroll-loops") */
#define likely(x) __builtin_expect(x, 1)
#define unlikely(x) __builtin_expect(x, 0)
#define All(x) x.begin(), x.end()
#define Rep(x, a, b) for(REGISTER int x = a; x <= b; ++x)
#define Resp(x, a, b) for(REGISTER int x = a; x >= b; --x)
#define rep(x, a, b) for(REGISTER int x = a; x < b; ++x)
#define resp(x, a, b) for(REGISTER int x = a; x > b; --x)
using LL = long long;
using pr = std::pair<int, int>;
template<typename T>
using vc = std::vector<T>;
template<typename T>
using vv = vc<vc<T>>;
template<typename T>
using sta = std::stack<T>;
constexpr int INF = INT_MAX;
constexpr int maxn = 110;

vv<int> mp(maxn);
vv<int> tmpMp(maxn);

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    /* std::cout.tie(null); */
#endif
    int f, v;
    std::cin >> f >> v;
    Rep(i, 1, f) {
        mp[i].reserve(v + 1);
        tmpMp[i].reserve(v + 1);
        Rep(j, 1, v) tmpMp[i][j] = -1;
        Rep(j, 1, v) std::cin >> mp[i][j];
    }
    
    Rep(i, 2, f) {
        int tmpMax = mp[i - 1][i - 1];
        int tmpInd = i - 1;
        /* rep(j, 2, i) tmpMax = mp[i - 1][j] > tmpMax ? mp[i - 1][j] : tmpMax; */
        /* rep(j, 2, i) { */
        /*     if (mp[i - 1][j] > tmpMax) { */
        /*         tmpMax = mp[i - 1][j], tmpInd = j; */
        /*     } */
        /* } */
        Rep(j, i, v) {
            mp[i][j] += tmpMax;
            tmpMp[i][j] = tmpInd;
            if (mp[i - 1][j] > tmpMax) {
                tmpMax = mp[i - 1][j], tmpInd = j;
            }
            /* tmpMax = mp[i - 1][j] > tmpMax ? mp[i - 1][j] : tmpMax; */
        }
    }

    int ans = mp[f][f];
    int tmpInd = f;
    /* Rep(i, 2, v) ans = mp[f][i] > ans ? mp[f][i] : ans; */
    Rep(i, f + 1, v) if (mp[f][i] > ans) {
        ans = mp[f][i];
        tmpInd = i;
    }
    std::cout << ans << "\n";
    sta<int> res;
    res.push(tmpInd);
    int count = 1;
    Resp(i, f, 2) {
        /* std::cout << " " << tmpMp[i][tmpInd]; */
        res.push(tmpMp[i][tmpInd]);
        tmpInd = tmpMp[i][tmpInd];
        count++;
    }
    /* std::cout << "\n"; */
    while (!res.empty()) {
        std::cout << res.top() << " \n"[count-- == 1];
        res.pop();
    }
    return 0;
}

