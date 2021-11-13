/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 105_1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 五  6/11 19:07:27 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
int rt, tot;
int fa[maxn], ch[maxn][2], val[maxn], siz[maxn], tg[maxn];
int dat[maxn];

struct Splay {
    void maintain(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1; }
    bool get(int x) { return x == ch[fa[x]][1]; }
    void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = siz[x] = tg[x] = 0;
    }

    void pushdown(int x) {
        if(x && tg[x]) {
            int &lefch = ch[x][0], &rigch = ch[x][1];
            swap(lefch, rigch);
            tg[lefch] ^= 1;
            tg[rigch] ^= 1;
            tg[x] = 0;    
        }
    }

    void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x);
        pushdown(y), pushdown(x);
        ch[y][chk] = ch[x][chk ^ 1];
        if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if(z) ch[z][y == ch[z][1]] = x;
        maintain(y);
        maintain(x);
    }
    
    void splay(int x, int goal) {
        //cout << x << " " << fa[x] << endl;
        for(int f = fa[x]; f = fa[x], f != goal; rotate(x)) {
            //cout << x << "    " << f << endl;
            //cout << val[x] << "      " << val[f] << endl;
            if(fa[f] != goal) rotate(get(x) == get(f) ? f : x);
            //cout << x << endl;
        }
        if(!goal) rt = x;
    }

    int kth(int k) {
        int cur = rt;
        while(1) {
            pushdown(cur);
            if(ch[cur][0] && k <= siz[ch[cur][0]]) cur = ch[cur][0];
            else {
                k -= siz[ch[cur][0]] + 1;
                //cout << "wwwwwww" << k << endl;
                if(k <= 0) {
                    //cout << "kkkkkkk" << endl;
                    //splay(cur);
                    //cout << "ssssss" << endl;
                    return cur;
                }
                cur = ch[cur][1];
            }
        }
    }

    int build(int l, int r, int f) {
        if (l > r) return 0;
        int mid = l + (r - l) / 2;
        tot++;
        int cur = tot;
        val[cur] = dat[mid], fa[cur] = f;
        ch[cur][0] = build(l, mid - 1, cur);
        ch[cur][1] = build(mid + 1, r, cur);
        maintain(cur);
        return cur;
    }

    void print(int x) {
        if(!x) return;
        pushdown(x);
        print(ch[x][0]);
        if(val[x] != -1 && val[x] != maxn) cout << val[x] << " ";
        print(ch[x][1]);

    }
}tree;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) dat[i + 1] = i;
    dat[1] = -1, dat[n + 2] = maxn;
    rt = tree.build(1, n + 2, 0);
    //tree.print(rt);
    //cout << endl;
    //cout << "tree build rt" << rt << endl;
    //cout << "11111111111111\n" << endl;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        int lef = tree.kth(x);
        int rig = tree.kth(y + 2);
        tree.splay(lef, 0);
        tree.splay(rig, lef);
        int r = ch[rt][1];
        tg[ch[r][0]] ^= 1;
        //tree.print(rt);
        //cout << endl;
    }
    tree.print(rt);
    cout << endl;
    return 0;
}

