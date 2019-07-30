#include <bits/stdc++.h>

using namespace std;

int n, k;

int solve(int l, int r, int k) {
    int mid = l + (r - l) / 2;
    long long num = (long long)(1 + mid) * mid / 2;
    if(num - (n - mid) == k) return n - mid;
    if(num - (n - mid) > k) return solve(l, mid - 1, k);
    if(num - (n - mid) < k) return solve(mid + 1, r, k);
}

int main() {
    scanf("%d %d", &n, &k);
    
    printf("%d\n", solve(1, n, k));
    return 0;
}
