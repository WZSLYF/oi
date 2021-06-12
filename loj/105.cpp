/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 105.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 四  6/10 10:08:46 2021
*   Describe: 
*   
**************************************************************************/

#include <iostream>
#include <map>
#include <utility>
#include <random>
#include <algorithm>

using namespace std;

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int maxn = 1e5 + 10;
struct node {
    int lef, rig;
    int key, val;
    int siz;
    bool revers;
}fhqtreap;
node tr[maxn];

int root, cnt;
#define trl(p) tr[p].lef
#define trr(p) tr[p].rig

mt19937 rnd(233);

int newnode(int val) {
    tr[++cnt].val = val;
    tr[cnt].key = rnd();
    tr[cnt].siz = 1;
    return cnt;
}

void pushup(int p) {
    tr[p].siz = tr[trl(p)].siz + tr[trr(p)].siz + 1;
}

void pushdown(int p) {
    swap(trl(p), trr(p));
    tr[trl(p)].revers ^= 1;
    tr[trr(p)].revers ^= 1;
    tr[p].revers = false;
}

pair<int, int> split(int p, int siz) {
    if(!p) return make_pair(0, 0);
    if(tr[p].revers) pushdown(p);
    if(siz <= tr[trl(p)].siz) {
        auto o = split(trl(p), siz);
        trl(p) = o.second;
        pushup(p);
        return make_pair(o.first, p);
    }
    else {
        auto o = split(trr(p), siz - tr[trl(p)].siz - 1);
        trr(p) = o.first;
        pushup(p);
        return make_pair(p, o.second);
    }
}

int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(tr[x].key < tr[y].key) {
        if(tr[x].revers) pushdown(x);
        tr[x].rig = merge(tr[x].rig, y);
        pushup(x);
        return x;
    }
    else {
        if(tr[y].revers) pushdown(y);
        tr[y].lef = merge(x, tr[y].lef);
        pushup(y);
        return y;
    }
}

void print(int p);

void reverse(int lef, int rig) {
    auto x = split(root, lef - 1);
    //print(x.first);
    //cout << endl;
   // print(x.second);
    //cout << endl;
    auto y = split(x.second, rig - lef + 1);
    tr[y.first].revers ^= 1;
    root = merge(merge(x.first, y.first), y.second);
}

void print(int p) {
    if(!p) return;
    if(tr[p].revers) pushdown(p);
    print(trl(p));
    cout << tr[p].val << " ";
    print(trr(p));
}

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) root = merge(root, newnode(i));
    //print(root);
    //cout << endl;
    while(m--) {
        int l, r;
        cin >> l >> r;
        reverse(l, r);
        //print(root);
        //cout << endl;
    }
    print(root);
    cout << endl;
    return 0;
}

