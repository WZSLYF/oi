/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年07月31日 星期日 11时15分47秒
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
    std::cout.tie(null);
#endif
    std::string s, t;
    std::cin >> s >> t;
    auto getres = [](std::string str) {
        int len = str.length();
        vc<pr> ans;
        char lastch = 0;
        int lastind = -1;
        for (int i = 0; i < len; ++i) {
            if (lastch == str[i]) continue;
            if (lastch != 0) ans.emplace_back(lastch, i - lastind);//, std::cout << lastch << " " << i - lastind << std::endl;
            lastch = str[i];
            lastind = i;
        }
        ans.emplace_back(lastch, len - lastind);
        /* std::cout << lastch << " " << str.size() - lastind << std::endl; */
        return ans;
    };

    auto res1 = getres(s);
    auto res2 = getres(t);

    if (res1.size() != res2.size()) {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (int i = 0; i < int(res1.size()); ++i) {
        bool ok = res1[i].first == res2[i].first && res1[i].second <= res2[i].second && 
            (res1[i].second == res2[i].second || res1[i].second >= 2);
        if (!ok) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}

