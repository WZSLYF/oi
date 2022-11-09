/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: b.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Wed Nov  9 11:17:58 2022
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
    int t;
    std::cin >> t;
    while (t--) {
        int len;
        std::cin >> len;
        std::string str;
        std::cin >> str;
        int len0 = std::count(str.begin(), str.end(), '0');
        int len1 = len - len0;
        auto getAns =[](int len0, int len1) -> LL {
            return len0 == 0 ? 1LL * len1 * len1 : (len1 == 0 ? 1LL * len0 * len0 : 1LL * len0 * len1);
        };
        LL ans = getAns(len0, len1);
        rep(i, 0, len) {
            int j = i;
            while (j < len && str[j] == str[i]) {
                j++;
            }
            ans = std::max(ans, 1LL * (j - i) * (j - i));
            i = j - 1;
        }

        std::cout << ans << "\n";
    }
    return 0;
}

