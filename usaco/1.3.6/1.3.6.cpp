#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
int n, dat[maxn];

int get(int a, int b) {
    int sum = 0;
    for(int i = 0; i < n; ++i) if(dat[i] < dat[0] + a) sum += (dat[0] + a - dat[i]) * (dat[0] + a - dat[i]); else break;
    for(int i = n - 1; i >= 0; --i) if(dat[i] > dat[n - 1] - b) sum += (dat[n - 1] - b - dat[i]) * (dat[n - 1] - b - dat[i]); else break;
    return sum;    
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &dat[i]);

    sort(dat, dat + n);
    int tmp = dat[n - 1] - dat[0] - 17;
    int ans = INT_MAX;
    for(int i = 0; i <= tmp; ++i) ans = min(ans, get(i, tmp - i));
    printf("%d\n", ans);
    return 0;
}
