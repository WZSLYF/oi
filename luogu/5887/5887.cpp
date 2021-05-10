#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)

const int maxn = 1e6 + 10;
int n, m, k, p[maxn];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    Rep(i, m) scanf("%d", &p[i]);
    int val = gcd(n, k);
    if(1 == val) printf("0\n");
    else {
        set<int> st;
        Rep(i, m) st.insert(p[i]%val);
        printf("%d\n", (val - st.size()) * n / val);
    }
    return 0;
}
