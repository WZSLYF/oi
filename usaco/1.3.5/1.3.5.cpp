#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
int n, match[maxn];
struct P {
    int x, y, ind;
}dat1[maxn], dat2[maxn];

bool cmp(const P &a, const P &b) {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool judge1(int num, int ind, int begin, bool into) {
    if(num != 1 && ind == begin && 0 == into) return true;
    if(0 == into) {
        if(dat1[ind].y == dat1[ind + 1].y) return judge1(num+1, ind + 1, begin, 1);
        return false;
    }
    else return judge1(num + 1, match[ind], begin, 0);
}

bool judge() {
    for(int i = 0; i < n; ++i) if(judge1(1, i, i, 0)) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d %d", &dat1[i].x, &dat1[i].y);

    sort(dat1, dat1 + n, cmp);
    for(int i = 0; i < n; ++i) dat1[i].ind = i, dat2[i].x = dat1[i].x, dat2[i].y = dat1[i].y, dat2[i].ind = i;
    
    int ans = 0;
    do {
        for(int i = 0; i < n; i += 2) match[dat2[i].ind] = dat2[i+1].ind, match[dat2[i+1].ind] = dat2[i].ind;
        if(judge()) {
            //for(int i = 0; i < n; ++i) printf("%d ", dat2[i].ind);
            //printf("\n");
            ans++;
        }
    }while(next_permutation(dat2, dat2 + n, cmp));
    
    int s = 1;
    for(int i = 0; i < n / 2; ++i) s *= 2;
    for(int i = n / 2; i > 0; --i) s *= i;
    printf("%d\n", ans/s);
    return 0;
}
