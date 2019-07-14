#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 10;
struct farmer {
    int Pi, Ai;
    inline bool operator < (const farmer& b) const { return Pi < b.Pi; }
}dat[maxn];
int N, M;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) scanf("%d %d", &dat[i].Pi, &dat[i].Ai);

    sort(dat, dat + M);
    int ans = 0, i = 0;
    while(N) {
        int tmp = N - dat[i].Ai;
        if(tmp < 0) ans += N * dat[i].Pi, N = 0;
        else ans += dat[i].Ai * dat[i].Pi, N = tmp, ++i;
    }
    printf("%d\n", ans);
    return 0;
}
