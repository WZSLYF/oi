#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)
const int maxn = 110;
int dat[maxn][maxn];
struct edge {
    int s, e, w;
    edge(int s = 0, int e = 0, int w = 0):s(s), e(e), w(w) {}
    bool operator < (const edge& b) const { return w < b.w; }
    void print() { printf("%d %d %d\n", s, e, w); }
}E[maxn*maxn];
int N, n;
int fa[maxn];

int getFather(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = getFather(fa[x]);
}

int kruscal() {
    int cnt = N;
    int ans = 0;
    Rep(i, N) fa[i] = i;
    Rep(i, n) {
        int fa1 = getFather(E[i].s);
        int fa2 = getFather(E[i].e);
        if(fa1 != fa2) {
            fa[fa1] = fa2;
            ans += E[i].w;
            cnt--;
            if(1 == cnt) break;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &N);

    Rep(i, N) Rep(j, N) scanf("%d", &dat[i][j]);
    
    n = 0;
    Rep(i, N) Rep(j, i) E[n++] = edge(i, j, dat[i][j]);
    
    //printf("%d\n", n);
    sort(E, E + n);
    //E[0].print();

    printf("%d\n", kruscal());
    return 0;
}
