/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: a.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年10月16日 星期日 11时13分21秒
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
constexpr int INF = INT_MAX;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    /* std::cout.tie(null); */
#endif
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, k;
        std::cin >> n >> k;
        std::string str;
        std::cin >> str;
        vc<int> p0(n + 1, 0);
        vc<int> p1(n + 1, 0);
        rep(i, 0, n) {
            p0[i + 1] = p0[i] + (str[i] == '0');
            p1[i + 1] = p1[i] + (str[i] == '1');
        }

        int num = 0;
        Rep(i, 0, n - k) {
            if (p0[i + k] - p0[i] == 0) {
                if (p1[i] == 0 && p1[n] - p1[i + k] == 0) {
                    num++;
                }
            }
        } 
        /* std::cout << (num == 1 ? "Yes" : "No") << std::endl; */
        std::cout << (num == 1 ? "Yes" : "No") << '\n';
    }
    return 0;
}

