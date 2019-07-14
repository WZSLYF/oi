#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
int dat[maxn][maxn];
int R;

int main() {
    scanf("%d", &R);

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j <= i; ++j) scanf("%d", &dat[i][j]);
    }

    for(int i = R-2; i >= 0; --i) {
        for(int j = 0; j <= i; ++j) dat[i][j] += max(dat[i + 1][j], dat[i + 1][j + 1]);
    }

    printf("%d\n", dat[0][0]);
    return 0;
}
