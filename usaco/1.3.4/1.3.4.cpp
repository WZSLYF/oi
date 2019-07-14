#include <bits/stdc++.h>

using namespace std;

#define f(i,j,n) for(int i = j; i <= n; ++i)
const int maxn = 10;
int n;
int dat[maxn];

bool isMatch(int a, int b) {
    if(a < b) swap(a, b);
    if((n - a) + b <= 2 || abs(a - b) <= 2) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    f(i, 0, 5) scanf("%d", &dat[i]);
    
    int ans = 0;
    f(i, 1, n) f(j, 1, n) f(k, 1, n) {
        if((isMatch(i, dat[0]) && isMatch(j, dat[1]) && isMatch(k, dat[2])) || 
            (isMatch(i, dat[3]) && isMatch(j, dat[4]) && isMatch(k, dat[5]))) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
