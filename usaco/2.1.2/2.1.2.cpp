#include <bits/stdc++.h>

using namespace std;

#define Rep(i, s, e) for(int i = s; i < e; ++i)

const int maxn = 3e4;
struct f {
    int x, y;
    inline bool operator < (const f& b) const{ return x*b.y < y*b.x; }
}dat[maxn];
int n, ans;

bool isEuq(const f& a, const f& b) {
    return a.x * b.y == b.x * a.y;
}

int gcd(int a, int b) {
    return 0 == b ? a : gcd(b, a%b);
}

int main() {
    scanf("%d", &n);
    
    ans = 0;
    Rep(i, 1, n + 1) Rep(j, 0, i + 1) {
        dat[ans].x = j;
        dat[ans].y = i;
        ans++;
    }

    sort(dat, dat + ans);
    
    printf("0/1\n");
    //Rep(i, 1, ans) printf("%d/%d\n", dat[i].x, dat[i].y);
    Rep(i, 1, ans) if(!isEuq(dat[i], dat[i - 1])) printf("%d/%d\n", dat[i].x / gcd(dat[i]. x, dat[i].y), dat[i].y / gcd(dat[i].x, dat[i].y));
    return 0;
}
