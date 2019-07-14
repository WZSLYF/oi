#include <bits/stdc++.h>

using namespace std;

int n;

const int dat[] = {2, 3, 5, 7};

bool isPrime(int x) {
    int tmp = sqrt(1.0 * x) + 0.5;
    for(int i = 2; i <= tmp; ++i) if(x%i == 0) return false;
    return true;
}

void dfs(int dep, int val) {
    if(dep == n) {
        printf("%d\n", val);
        return;
    }

    if(!dep) {
        for(int i = 0; i < 4; ++i) dfs(dep + 1, dat[i]);
    }
    else {
        for(int i = 1; i <= 9; i += 2) if(isPrime(val*10 + i)) dfs(dep + 1, val * 10 + i);
    }
}

int main() {
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}
