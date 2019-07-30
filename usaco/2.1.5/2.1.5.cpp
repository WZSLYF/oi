#include <bits/stdc++.h>

using namespace std;

int N, B, D;
vector<int> ans;

bool judge(int a, int b) {
    int num = 0;
    for(int i = 0; i < B; ++i) {
        if(a%2 != b%2) num++;
        a /= 2;
        b /= 2;
        if(num >= D) break;
    }
    return num >= D;
}

int main() {
    scanf("%d %d %d", &N, &B, &D);

    ans.push_back(0);
    for(int i = 1; i < (1 << B); ++i) {
        bool flags = true;
        for(int j = 0; j < ans.size(); ++j) if(!judge(i, ans[j])) { flags = false; break; }
        if(flags) ans.push_back(i);
        if(ans.size() >= N) break;
    }

    for(int i = 0; i < ans.size(); ++i) {
        if(i && i % 10 == 0) printf("\n");
        if((i + 1) % 10 != 1) printf(" ");
        printf("%d", ans[i]);
    }
    if(ans.size() % 10) printf("\n");
    return 0;
}
