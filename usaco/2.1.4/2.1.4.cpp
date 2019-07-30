#include <bits/stdc++.h>

using namespace std;

const int maxn = 26;
struct node {
    int x[maxn];
};
node ans, dat[maxn];
int n, G;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) scanf("%d", &ans.x[i]);

    scanf("%d", &G);

    for(int i = 0; i < G; ++i) {
        for(int j = 0; j < n; ++j) scanf("%d", &dat[i].x[j]);
    }
    
    int res = G;
    int ind = 1 << G;
    for(int i = 1; i < (1 << G); ++i) {
        node tmp;
	for(int j = 0; j < n; ++j) tmp.x[j] = 0;
        int num = 0;
        for(int j = 0; j < G; ++j) if(i & (1 << j)) {
            num++;
            for(int k = 0; k < n; ++k) tmp.x[k] += dat[j].x[k];
        }
        
        bool flags = true;
        for(int j = 0; j < n; ++j) if(tmp.x[j] < ans.x[j]) { flags = false; break; }
        if(flags) {
            if(res > num) {
                res = num;
                ind = i;
            }
	    else if(res == num && ind > i) ind = i;
        }
    }

    printf("%d", res);
    for(int i = 0; i < G; ++i) if(ind & (1 << i)) printf(" %d", i + 1);
    printf("\n");
    return 0;
}
