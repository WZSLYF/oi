#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    if(k > (n-1)*(m-1) || k > m * n - 2) printf("-1\n");
    else printf("%lld\n", m+n-2);
    return 0;
}
