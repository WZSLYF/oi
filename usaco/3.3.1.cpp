/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.3.1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 17 Jun 2021 11:54:13 AM CST
*   Describe: 
*   
**************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 510;
const int maxm = 500;
struct edge {
    int to;
    bool exits;         //判断这条边是否存在，过程需要删边
    int revref;         //这个记录是x->y在x中是第几条边
    
    bool operator<(const edge& b) const { return to < b.to; }
};

vector<edge> mp[maxn];
int cnt[maxn];   //用于跳过已经访问过的边
stack<int> ans;
int deg[maxn], reftop[maxn]; //度数 和 查找x->y在x中是第几条边

void euler(int x) {
    for(int &i = cnt[x]; i < (int)mp[x].size();) {
        if(mp[x][i].exits) {
            edge e = mp[x][i];
            mp[x][i].exits = 0;
            mp[e.to][e.revref].exits = 0;  //这里对应删除x -> y 和 y- > x;
            ++i;
            euler(e.to);
        }
        else {
            ++i;
        }
    }
    ans.push(x);
}

int main() {
#ifdef Debug
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdin);
#endif
    for(int i = 1; i <= maxm; ++i) mp[i].reserve(1050); //避免vector重新动态分配空间

    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp[a].push_back((edge){b, 1, 0});
        mp[b].push_back((edge){a, 1, 0});
        ++deg[a];
        ++deg[b];
    }

    for(int i = 1; i <= maxm; ++i) {
        if(!mp[i].empty()) {
            sort(mp[i].begin(), mp[i].end());
        }
    }

    for(int i = 1; i <= maxm; ++i) {
        for(int j = 0; j < (int)mp[i].size(); ++j)
            mp[i][j].revref = reftop[mp[i][j].to]++;
    }

    int bv = 0;
    for(int i = 1; i <= maxm; ++i) {
        if(!deg[bv] && deg[i]) bv = i;
        else if(!(deg[bv] & 1) && (deg[i] & 1)) bv = i;
    }

    euler(bv);

    while(!ans.empty()) {
        printf("%d\n", ans.top());
        ans.pop();
    }
    return 0;
}

