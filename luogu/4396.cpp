/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 4396.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 23 Jun 2021 11:01:51 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) (x & (-x))

const int maxn = 1e5 + 10;
int n, m, dat[maxn];
int pos[maxn], ans[maxn], res[maxn];
int tr[maxn], t[maxn], cnt[maxn];
struct Ques {
    int l, r, a, b, id;
}q[maxn];

void add(int *t, int ind, int x) {
    for(; ind <= maxn; ind += lowbit(ind)) t[ind] += x;
}

int getsum(int *t, int ind) {
    int tmp = 0;
    for(; ind; ind -= lowbit(ind)) tmp += t[ind];
    return tmp;
}

int Add(int x) {
    if(!cnt[x]) {
        add(tr, x, 1);
    }
    ++cnt[x];
    add(t, x, 1);
}

int Sub(int x) {
    --cnt[x];
    if(!cnt[x]) {
        add(tr, x, -1);
    }
    add(t, x, -1);
}

bool cmp(const Ques &a, const Ques &b) {
    if(pos[a.l] != pos[b.l]) return a.l < b.l;
    if(pos[a.l] & 1) return a.r < b.r;
    return a.r > b.r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int b = sqrt(n);
    for(int i = 1; i <= n; ++i) cin >> dat[i], pos[i] = (i - 1) / b;
    for(int i = 1; i <= m; ++i) cin >> q[i].l >> q[i].r >> q[i].a >> q[i].b, q[i].id = i;
    
    sort(q + 1, q + m + 1, cmp);
    int lef = 1, rig = 0;
    for(int i = 1; i <= m; ++i) {
        while(lef > q[i].l) Add(dat[--lef]);
        while(rig < q[i].r) Add(dat[++rig]);
        while(lef < q[i].l) Sub(dat[lef++]);
        while(rig > q[i].r) Sub(dat[rig--]);
        ans[q[i].id] = getsum(t, q[i].b) - getsum(t, q[i].a - 1);
        res[q[i].id] = getsum(tr, q[i].b) - getsum(tr, q[i].a - 1);
    }
    for(int i = 1; i <= m; ++i) cout << ans[i] << " " << res[i] << endl;
    return 0;
}

