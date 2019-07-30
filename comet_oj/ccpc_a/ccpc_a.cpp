#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        scanf("%d %d", &n, &k);
        long long tmp;
        long long val = 1;
        for(int j = 1; j < 32; ++j) {
            val = (pow(k*1.0, j) - 1) / (k - 1);
            if(val == n) { printf("%d\n", 2*j - 2); break; }
            else if(val > n && n > tmp) {
                if(n > tmp) { printf("%d\n", 2*j - 2); break; }
                else { printf("%d\n", 2*j - 3); break;}
            }
            tmp = val;
        }
    }
    return 0;
}
