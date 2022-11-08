/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: 101.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Tue Nov  8 12:06:33 2022
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
constexpr int maxn = 210;

struct edge {
    int to;
    int revref;
    bool exits;

    edge(int _to, int _revref, bool _exits) : to(_to), revref(_revref), exits(_exits) {}

    bool operator<(const edge& b) const { return to < b.to; }
};

vc<edge> mp[maxn];
vc<pr> dat;
bool isvis[maxn];
int cnt[maxn];
sta<int> ans;
int deg[maxn], reftop[maxn];

void euler(int u) {
    for (int &v = cnt[u]; v < (int)mp[u].size();) {
        if (mp[u][v].exits) {
            edge tmp = mp[u][v];
            mp[u][v].exits = false;
            mp[tmp.to][tmp.revref].exits = false;
            ++v;
            euler(tmp.to);
        } else {
            ++v;
        }
    }
    ans.push(u);
}

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    /* std::cout.tie(null); */
#endif
    rep(i, 1, maxn) mp[i].reserve(maxn);
    memset(isvis, false, sizeof(isvis));

    int N;
    std::cin >> N;
    Rep(i, 1, N) {
        int a, b;
        std::cin >> a >> b;
        a++, b++;
        dat.push_back(std::make_pair(a, b));
        mp[a].emplace_back(b, 0, true);
        if (a != b) mp[b].emplace_back(a, 0, true);
        ++deg[a], ++deg[b];
    }
    
    rep(i, 1, maxn) if (!mp[i].empty()) sort(All(mp[i]));

    rep(i, 1, maxn) rep(j, 0, (int)mp[i].size()) mp[i][j].revref = reftop[mp[i][j].to]++;

    int tmp = 0;
    rep(i, 1, maxn) if (deg[i] & 1) tmp++;
    if (tmp && tmp != 2) {
        std::cout << "No solution" << "\n";
        return 0;
    }

    int bu = 0;
    rep(i, 1, maxn) {
        if (!deg[bu] && deg[i]) bu = i;
        else if (!(deg[bu] & 1) && (deg[i] & 1)) bu = i;
    }

    euler(bu);

    if (ans.size() != N + 1) {
        std::cout << "No solution" << "\n";
        return 0;
    }

    int u = ans.top(), v = -1;
    ans.pop();
    while (!ans.empty()) {
        v = ans.top();
        rep(i, 0, (int)dat.size()) {
            if (!isvis[i]) {
                if (dat[i].first == u && dat[i].second == v) {
                    std::cout << i + 1 << " +" << "\n";
                    isvis[i] = true;
                    u = v;
                }
                else if (dat[i].first == v && dat[i].second == u) {
                    std::cout << i + 1 << " -" << "\n";
                    isvis[i] = true;
                    u = v;
                }
            }
        }
        ans.pop();
    }
    return 0;
}

