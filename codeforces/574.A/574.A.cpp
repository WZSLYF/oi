#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
int n, k, dat[maxn];

int main() {
    scanf("%d %d", &n, &k);
    int a;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        dat[a-1]++;
    }
    int tmp = n % 2 ? n / 2 + 1 : n / 2;
    int ans = 0;
    for(int i = 0; i < k; ++i) {
        tmp -= dat[i] / 2;
        ans += dat[i] / 2 * 2;
    }
    for(int i = 0; tmp && i < k; ++i) {
        tmp -= dat[i] % 2;
        ans += dat[i] % 2;
    }
    printf("%d\n", ans);
    return 0;
}
