#include <bits/stdc++.h>

using namespace std;

const int maxn = 21;
bool isVis[maxn][maxn][maxn];
int A, B, C;
set<int> ans;

void dfs(int a, int b, int c) {
    if(!a) ans.insert(c);
    if(a) {
        int tmp = min(a, B - b);
        if(!isVis[a-tmp][b+tmp][c]) isVis[a-tmp][b+tmp][c] = 1, dfs(a - tmp, b + tmp, c), isVis[a-tmp][b+tmp][c] = 0;
        tmp = min(a, C - c);
        if(!isVis[a-tmp][b][c+tmp]) isVis[a-tmp][b][c+tmp] = 1, dfs(a - tmp, b, c + tmp), isVis[a-tmp][b][c+tmp] = 0;
    }

    if(b) {
        int tmp = min(A - a, b);
        if(!isVis[a+tmp][b-tmp][c]) isVis[a+tmp][b-tmp][c] = 1, dfs(a + tmp, b - tmp, c), isVis[a+tmp][b-tmp][c] = 0;
        tmp = min(b, C - c);
        if(!isVis[a][b-tmp][c+tmp]) isVis[a][b-tmp][c+tmp] = 1, dfs(a, b - tmp, c + tmp), isVis[a][b-tmp][c+tmp] = 0;
    }

    if(c) {
        int tmp = min(A - a, c);
        if(!isVis[a+tmp][b][c-tmp]) isVis[a+tmp][b][c-tmp] = 1, dfs(a + tmp, b, c - tmp), isVis[a+tmp][b][c-tmp] = 0;
        tmp = min(B - b, c);
        if(!isVis[a][b+tmp][c-tmp]) isVis[a][b+tmp][c-tmp] = 1, dfs(a, b + tmp, c - tmp), isVis[a][b+tmp][c-tmp] = 0;
    }
}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    
    isVis[0][0][C] = 1;
    dfs(0, 0, C);
    
    for(set<int>::iterator iter = ans.begin(); iter != ans.end(); ++iter) {
        if(iter != ans.begin()) printf(" ");
        printf("%d", *iter);
    }
    printf("\n");
    return 0;
}
