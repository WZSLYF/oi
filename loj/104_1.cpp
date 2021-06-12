/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 104_1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 五  6/11 10:46:36 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int rt, tot, fa[maxn], ch[maxn][2], val[maxn], cnt[maxn], siz[maxn];

struct Splay {
    void maintain(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x]; }
    bool get(int x) { return x == ch[fa[x]][1]; }
    void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = cnt[x] = siz[x] = 0;
    }
    
    void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x);
        ch[y][chk] = ch[x][chk ^ 1];
        if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if(z) ch[z][y == ch[z][1]] = x;
        maintain(y);
        maintain(x);
    }

    void splay(int x) {
        for(int f = fa[x]; f = fa[x], f; rotate(x))
            if(fa[f]) rotate(get(x) == get(f) ? f : x);
        rt = x;
    }

    void insert(int k) {
        if(!rt) {
            tot++;
            val[tot] = k;
            cnt[tot] = 1;
            rt = tot;
            maintain(rt); //空节点新建没必要从孩子更新吧，孩子节点都是空的
            return;
        }
        int cur = rt, f = 0;
        while(1) {
            if(val[cur] == k) {
                cnt[cur]++;
                maintain(cur);
                if(f) maintain(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = ch[cur][val[cur] < k];
            if(!cur) {
                tot++;
                val[tot] = k;
                cnt[tot] = 1;
                fa[tot] = f;
                ch[f][val[f] < k] = tot;
                maintain(tot);
                maintain(f);
                splay(tot);
                break;
            }
        }
    }

    int rk(int k) {
        int res = 0, cur = rt;
        while(1) {
            if(k < val[cur]) {
                cur = ch[cur][0];
            }
            else {
                res += siz[ch[cur][0]];
                if(k == val[cur]) {
                    splay(cur);
                    return res + 1;
                }
                res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }

    int kth(int k) {
        int cur = rt;
        while(1) {
            if(ch[cur][0] && k <= siz[ch[cur][0]]) {
                cur = ch[cur][0];
            }
            else {
                k -= cnt[cur] + siz[ch[cur][0]];
                if(k <= 0) {
                    splay(cur);
                    return val[cur];
                }
                cur = ch[cur][1];
            }
        }
    }

    int pre() {
        int cur = ch[rt][0];
        if(!cur) return cur;
        while(ch[cur][1]) cur = ch[cur][1];
        splay(cur);
        return cur;
    }

    int nxt() {
        int cur = ch[rt][1];
        if(!cur) return cur;
        while(ch[cur][0]) cur = ch[cur][0];
        splay(cur);
        return cur;
    }

    void del(int k) {
        rk(k);
        if(cnt[rt] > 1) {
            cnt[rt]--;
            maintain(rt);
            return;
        }
        if(!ch[rt][0] && !ch[rt][1]) {
            clear(rt);
            rt = 0;
            return;
        }
        if(!ch[rt][0]) {
            int cur = rt;
            rt = ch[rt][1];
            fa[rt] = 0;
            clear(cur);
            return;
        }
        if(!ch[rt][1]) {
            int cur = rt;
            rt = ch[rt][0];
            fa[rt] = 0;
            clear(cur);
            return;
        }
        int cur = rt;
        int x = pre();
        fa[ch[cur][1]] = x;
        ch[x][1] = ch[cur][1];
        clear(cur);
        maintain(rt);
    }
} tree;

int main()
{
    int n, opt, x;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> opt >> x;
        if(1 == opt) tree.insert(x);
        else if(2 == opt) tree.del(x);
        else if(3 == opt) cout << tree.rk(x) << endl;
        else if(4 == opt) cout << tree.kth(x) << endl;
        else if(5 == opt) tree.insert(x), cout << val[tree.pre()] << endl, tree.del(x);
        else tree.insert(x), cout << val[tree.nxt()] << endl, tree.del(x);
    }
    return 0;
}

