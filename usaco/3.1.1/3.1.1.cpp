#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)
const int maxn = 110;
const int INF = ~0U >> 1;
int dat[maxn][maxn], dis[maxn], N;
bool isVis[maxn];

int prim() {
    int ans = 0;
    Rep(i, N) isVis[i] = false;
    Rep(i, N) dis[i] = INF;
    dis[0] = 0;
    Rep(i, N) {
        int mark = -1;
        Rep(j, N) {
            if(!isVis[j]) {
                if(-1 == mark) mark = j;
                else if(dis[j] < dis[mark]) mark = j;
            }
        }
        if(-1 == mark) break;
        //printf("%d\n", INF);
        isVis[mark] = true;
        ans += dis[mark];
        Rep(j, N) if(!isVis[j]) {
            dis[j] = min(dis[j], dat[mark][j]);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &N);

    Rep(i, N) Rep(j, N) scanf("%d", &dat[i][j]);

    printf("%d\n", prim());
    return 0;
}
