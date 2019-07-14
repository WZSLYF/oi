#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
int n, ans, match[maxn];
struct P {
    int x, y;
    inline bool operator < (const P& b) const {
        if(y == b.y) return x < b.x;
        return y < b.y;
    }
}dat[maxn];

bool judge1(int num, int ind, int S, bool into) {
    if(1 != num && ind == S && 0 == into) return true;
    if(0 == into) {
        if(dat[ind].y == dat[ind + 1].y) return judge1(num + 1, ind + 1, S, 1);
        return false;
    }
    return judge1(num + 1, match[ind], S, 0);
}

bool judge() {
    //printf("1\n");
    for(int i = 0; i < n; ++i) if(judge1(1, i, i, 0)) return true;
    return false;
}

void getMatch(int x) {
    if(x == n) {
        if(judge()) ans++;
        return;
    }
    if(-1 == match[x]) {
        for(int i = x + 1; i < n; ++i) if(-1 == match[i]) {
            match[x] = i;
            match[i] = x;
            getMatch(x + 1);
            match[x] = -1;
            match[i] = -1;
        }
    }
    else getMatch(x + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d %d", &dat[i].x, &dat[i].y);

    sort(dat, dat + n);
    for(int i = 0; i < n; ++i) match[i] = -1;
    ans = 0;
    getMatch(0);
    printf("%d\n", ans);
    return 0;
}
