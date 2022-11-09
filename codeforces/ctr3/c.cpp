/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Wed Nov  9 17:35:34 2022
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

void solve() {
    int len;
    std::cin >> len;

    std::string str1, str2;
    std::cin >> str1 >> str2;
    rep(i, 1, len) {
        if (str1[i] ^ str2[i] ^ str1[0] ^ str2[0]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
    
    vc<pr> ans;
    rep(i, 0, len) {
        if (str1[i] == '1') ans.push_back({i, i + 1});
    }

    if (str1[0] ^ str2[0] ^ (ans.size() & 1)) {
        ans.push_back({0, 1});
        ans.push_back({1, len});
        ans.push_back({0, len});
    }

    std::cout << ans.size() << "\n";
    for (auto &iter : ans) {
        std::cout << iter.first + 1 << " " << iter.second << "\n";
    }
}

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
        solve();
    }
    return 0;
}

