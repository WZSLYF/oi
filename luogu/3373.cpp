#include <bits/stdc++.h>

using namespace std;

#define ll long long
//#define lefind (ind << 1)
//#define rigind ((ind << 1) | 1)

const int maxn = 1e5 + 10;
int dat[maxn];
ll sum[4 * maxn], mul[4 * maxn], add[4 * maxn];
int n, m, p;

void build(int l, int r, int ind) {
    int lefind = (ind << 1), rigind = (ind << 1) | 1;
    mul[ind] = 1;
    if(l == r) {
        sum[ind] = dat[l];
        //add[ind] = 0;
        return;
    }
    
    int mid = l + (r - l) / 2;
    build(l, mid, lefind);
    build(mid + 1, r, rigind);
    sum[ind] = sum[lefind] + sum[rigind];
    sum[ind] %= p;
}

void update(int l, int r, int ind) {
    int mid = l + (r - l) / 2;
    int lefind = (ind << 1), rigind = (ind << 1) | 1;
    if(mul[ind] != 1) {
        sum[lefind] *= mul[ind];
        sum[lefind] %= p;
        sum[rigind] *= mul[ind];
        sum[rigind] %= p;
        mul[lefind] *= mul[ind];
        mul[lefind] %= p;
        mul[rigind] *= mul[ind];
        mul[rigind] %= p;
        add[lefind] *= mul[ind];
        add[lefind] %= p;
        add[rigind] *= mul[ind];
        add[rigind] %= p;
        mul[ind] = 1;
    }

    if(add[ind]) {
        sum[lefind] += add[ind] * (mid - l + 1);
        sum[lefind] %= p;
        sum[rigind] += add[ind] * (r - mid);
        sum[rigind] %= p;
        add[lefind] += add[ind];
        add[lefind] %= p;
        add[rigind] += add[ind];
        add[rigind] %= p;
        add[ind] = 0;
    }
}

void change1(int l, int r, int lef, int rig, int ind, ll val) {
    int lefind = (ind << 1), rigind = (ind << 1) | 1;
    if(lef <= l && r <= rig) {
        sum[ind] += (r - l + 1) * val;
        sum[ind] %= p;
        add[ind] += val;
        add[ind] %= p;
        return;
    }
    int mid = l + (r - l) / 2;
    update(l, r, ind);
    if(lef <= mid) change1(l, mid, lef, rig, lefind, val);
    if(rig > mid) change1(mid + 1, r, lef, rig, rigind, val);
    sum[ind] = sum[lefind] + sum[rigind];
    sum[ind] %= p;
}

void change2(int l, int r, int lef, int rig, int ind, ll val) {
    int lefind = (ind << 1), rigind = (ind << 1) | 1;
    if(lef <= l && r <= rig) {
        sum[ind] *= val;
        sum[ind] %= p;
        add[ind] *= val;
        add[ind] %= p;
        mul[ind] *= val;
        mul[ind] %= p;
        return;
    }
    int mid = l + (r - l) / 2;
    update(l, r, ind);
    if(lef <= mid) change2(l, mid, lef, rig, lefind, val);
    if(rig > mid) change2(mid + 1, r, lef, rig, rigind, val);
    sum[ind] = (sum[lefind] + sum[rigind]) % p;
}

ll getsum(int l, int r, int lef, int rig, int ind) {
    int lefind = (ind << 1), rigind = (ind << 1) | 1;
    if(lef <= l && r <= rig) {
        return sum[ind];
    }
    int mid = l + (r - l) / 2;
    update(l, r, ind);
    ll ans = 0;
    if(lef <= mid) ans += getsum(l, mid, lef, rig, lefind);
    if(rig > mid) ans += getsum(mid + 1, r, lef, rig, rigind);
    return ans % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p;
    for(int i = 1; i <= n; ++i) cin >> dat[i];
    build(1, n, 1);
    for(int i = 1; i <= m; ++i) {
        int opt;
        cin >> opt;
        if(1 == opt) {
            int x, y;
            ll val;
            cin >> x >> y >> val;
            change2(1, n, x, y, 1, val);
        }
        else if(2 == opt) {
            int x, y;
            ll val;
            cin >> x >> y >> val;
            change1(1, n, x, y, 1, val);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << getsum(1, n, x, y, 1) << endl;
        }
    }
    return 0;
}
