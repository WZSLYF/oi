#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int dat[maxn][maxn], ans[maxn][maxn];
bool isVis[maxn];
vector<int> ret;
int N;

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dat[a][b] += c;
    }

    for(int i = 1; i < maxn; ++i) {
        for(int j = 1; j < maxn; ++j) isVis[j] = 0, ans[i][j] = dat[i][j];
        ret.clear();
        for(int j = 1; j < maxn; ++j) if(i != j && !isVis[j] && ans[i][j] > 50) isVis[j] = 1, ret.push_back(j);
        
        int len = ret.size();
        for(int j = 0; j < len; ++j) {
            for(int k = 1; k < maxn; ++k) {
                ans[i][k] += dat[ret[j]][k];
                if(i != k && !isVis[k] && ans[i][k] > 50) isVis[k] = 1, ret.push_back(k), len++;
            }
        }
    }

    for(int i = 1; i < maxn; ++i) {
        for(int j = 1; j < maxn; ++j) {
            if(i != j && ans[i][j] > 50) printf("%d %d\n", i, j);
        }
    }
    return 0;
}
