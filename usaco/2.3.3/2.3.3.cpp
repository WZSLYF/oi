#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
char str[maxn];
int N;
vector<int> ret;

bool judge() {
    int val = 1;
    ret.clear();
    for(int i = 1; i < N; ++i) if(str[i - 1] == '0') {
        val *= 10;
        val += i + 1;
    }
    else {
        ret.push_back(val);
        val = i + 1;
    }
    ret.push_back(val);

    val = ret[0];
    int i = 1;
    for(int j = 1; j < N; ++j) if(str[j - 1] == '1') val += ret[i++];
    else if(str[j - 1] == '2') val -= ret[i++];
    return val == 0;
}

void dfs(int cur) {
    if(cur == N) {
        if(judge()) {
            for(int i = 1; i < N; ++i) printf("%d%c", i, str[i - 1] == '1' ? '+' : str[i - 1] == '2' ? '-' : ' ');
            printf("%d\n", N);
        }
        return;
    }
    for(int i = 0; i < 3; ++i) {
        str[cur - 1] = i + '0';
        dfs(cur + 1);
    }
}

int main() {
    scanf("%d", &N);
    
    dfs(1);
    return 0;
}
