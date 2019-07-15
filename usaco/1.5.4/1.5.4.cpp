#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)

const int maxn = 15;
int n, num, ans, Match[maxn];
bool isMatch[maxn];

void dfs(int cur) {
    if(cur >= n) {
        if(num < 3) Rep(i, n) {
            if(i) printf(" ");
            printf("%d", Match[i] + 1);
        }
        if(num < 3) printf("\n");
        num++;
        ans++;
        return;
    }

    Rep(i, n) if(!isMatch[i]) {
        bool flags = true;
        Rep(j, cur) if(cur - j == abs(Match[j] - i)) {
            flags = false;
            break;
        } 
        if(flags) {
            Match[cur] = i;
            isMatch[i] = 1;
            dfs(cur + 1);
            Match[cur] = 0;
            isMatch[i] = 0;
        }
    }
}

int main() {

    scanf("%d", &n);

    num = 0;
    ans = 0;
    dfs(0);
    printf("%d\n", ans);

    return 0;
}
