/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: 1341.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Tue Nov  8 10:35:30 2022
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
constexpr int maxn = 55;

struct edge {
    int to;
    int revref;
    bool exits;

    edge(int _to, int _revref,bool  _exits) : to(_to), revref(_revref), exits(_exits) {}

    bool operator<(const edge& b) const { return to < b.to; }
};

vc<edge> mp[maxn];
int cnt[maxn];
sta<int> ans;
int deg[maxn], reftop[maxn];

void euler(int u) {
    for (int &i = cnt[u]; i < (int) mp[u].size();) {
        if (mp[u][i].exits) {
            edge tmp = mp[u][i];
            mp[u][i].exits = false;
            mp[tmp.to][tmp.revref].exits = false;
            ++i;
            euler(tmp.to);
        } else {
            ++i;
        }
    }
    ans.push(u);
}

#define handle(x) (x >= 'a' && x <= 'z') ? x - 'a' + 27 : (x >= 'A' && x <= 'Z') ? x - 'A' + 1 : 0;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    /* std::cout.tie(null); */
#endif
    rep(i, 1, maxn) mp[i].reserve(maxn);
    int n;
    std::cin >> n;
    Rep(i, 1, n) {
        char u, v;
        std::cin >> u >> v;
        int tmpu = handle(u);
        int tmpv = handle(v);
        mp[tmpu].emplace_back(tmpv, 0, true);
        if (tmpu != tmpv) mp[tmpv].emplace_back(tmpu, 0, true);
        ++deg[tmpu], ++deg[tmpv];
    }

    rep(i, 1, maxn) if (!mp[i].empty()) sort(All(mp[i]));

    rep(i, 1, maxn) rep(j, 0, (int)mp[i].size()) mp[i][j].revref = reftop[mp[i][j].to]++;

    int tmp = 0;
    rep(i, 1, maxn) if (deg[i] & 1) tmp++;
    if (tmp && tmp != 2) {
        std::cout << "No Solution" << "\n";
        return 0;
    }

    int bu = 0;
    rep(i, 1, maxn) {
        if (!deg[bu] && deg[i]) bu = i;
        else if (!(deg[bu] & 1) && (deg[i] & 1)) bu = i;
    }

    euler(bu);
    
    if (ans.size() != n + 1) {
        std::cout << "No Solution" << "\n";
        return 0;
    }

    while (!ans.empty()) {
        int tmp = ans.top();
        std::cout << (char)(tmp > 26 ? tmp - 27 + 'a' : tmp - 1 + 'A');
        ans.pop();
    }
    std::cout << "\n";

    return 0;
}

