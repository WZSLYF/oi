#include <bits/stdc++.h>

using namespace std;

const int maxn = 160;
const int INF = 0x7fffffff;
int N;
struct point {
    int x, y;
}dat2[maxn];
char str[maxn];
double dat[maxn][maxn];

int sqr(int x) {
    return x * x;
}

double dis(int i, int j) {
    return sqrt(sqr(dat2[i].x - dat2[j].x) + sqr(dat2[i].y - dat2[j].y));
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d %d", &dat2[i].x, &dat2[i].y);
    
    for(int i = 0; i < N; ++i) {
        scanf("%s", str);
        for(int j = 0; j < N; ++j) if(str[j] == '1') dat[i][j] = dis(i, j);
        else dat[i][j] = INF;
    }
    
    //for(int i = 0; i < N; ++i) {
      //for(int j = 0; j < N; ++j) printf("%lf ", dat[i][j]);
      //printf("\n");
   //}


    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) if(i != j && dat[i][k] != INF && dat[k][j] != INF && dat[i][j] > dat[i][k] + dat[k][j]) {
                dat[i][j] = dat[i][k] + dat[k][j];
            } 
        }
    }

    //for(int i = 0; i < N; ++i) {
        //for(int j = 0; j < N; ++j) printf("%lf ", dat[i][j]);
        //printf("\n");
    //}
    
    double ans = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) if(dat[i][j] != INF) ans = max(ans, dat[i][j]);
    }

    double ret = INF;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i != j && dat[i][j] == INF) {
                double Max1 = 0, Max2 = 0;
                for(int k = 0; k < N; ++k) {
                    if(dat[i][k] != INF) Max1 = max(Max1, dat[i][k]);
                    if(dat[j][k] != INF) Max2 = max(Max2, dat[j][k]);
                }
                ret = min(ret, Max1 + Max2 + dis(i, j));
            }
        }
    }

    printf("%.6lf\n", max(ans, ret));
    return 0;
}
