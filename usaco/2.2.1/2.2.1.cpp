#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
int ans[maxn];
const int dat[] = {1, 5, 10, 50, 100, 500, 1000};
const char str[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void calc(int n) {
    for(int i = 6; i >= 0; --i) {
        ans[i] += n / dat[i];
        n %= dat[i];
        if(i && i%2 == 0 && n >= dat[i] - dat[i - 2]) {
            ans[i] += n / (dat[i] - dat[i - 2]);
            ans[i - 2] += n / (dat[i] - dat[i - 2]);
            n %= dat[i] - dat[i - 2];
        }
        if(i && i%2 == 1 && n >= dat[i] - dat[i - 1]) {
            ans[i] += n / (dat[i] - dat[i - 1]);
            ans[i - 1] += n / (dat[i] - dat[i - 1]);
            n %= dat[i] - dat[i - 1];
        }
        if(0 == n) break;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) calc(i);
    for(int i = 0; i < 7; ++i) if(ans[i]) printf("%c %d\n", str[i], ans[i]);
    return 0;
}
