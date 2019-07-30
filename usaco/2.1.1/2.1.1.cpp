#include <bits/stdc++.h>

using namespace std;

#define Rep(i, s, e) for(int i = s; i <= e; ++i)
#define Rep1(i, s, e) for(int i = e; i >= s; --i)

const int maxn = 55;
int dat1[maxn][maxn], dat2[maxn][maxn], N, M, n, ans[maxn * maxn], res, resx, resy, resind;
bool isVis[maxn][maxn];
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};
const int Val[] = {8, 4, 2, 1};
const char str[] = {'S', 'E', 'N', 'W'};

void dfs1(int x, int y, int val) {
    isVis[x][y] = 1;
    dat2[x][y] = n;
    ans[n]++;
    Rep(i, 0, 3) if(val >= Val[i]) val -= Val[i];
    else if(!isVis[x + X[i]][y + Y[i]]) dfs1(x + X[i], y + Y[i], dat1[x + X[i]][y + Y[i]]);
}

int main() {
    scanf("%d %d", &M, &N);
    Rep(i, 1, N) Rep(j, 1, M) scanf("%d", &dat1[i][j]);

    n = 0;
    res = 0;
    Rep(i, 1, N) Rep(j, 1, M) if(!isVis[i][j]) ++n, dfs1(i, j, dat1[i][j]), res = max(res, ans[n]);
    
    //Rep(i, 1, N) Rep(j, 1, M) printf("%d", dat2[i][j]);
    printf("%d\n", n);
    printf("%d\n", res);

    res = 0;
    Rep(j, 1, M) Rep1(i, 1, N) {
        int tmp = dat1[i][j];
        Rep1(k, 0, 3) if(tmp >= Val[k] && dat2[i + X[k]][j + Y[k]] && dat2[i][j] != dat2[i + X[k]][j + Y[k]]) {
            if(res < ans[dat2[i][j]] + ans[dat2[i + X[k]][j + Y[k]]]) {
                res = ans[dat2[i][j]] + ans[dat2[i + X[k]][j + Y[k]]];
                resx = i;
                resy = j;
                resind = k;
            }
            tmp -= Val[k];
        }
    }

    printf("%d\n", res);
    printf("%d %d %c\n", resx, resy, str[resind]);
    return 0;
}
