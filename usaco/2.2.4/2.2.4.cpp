#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> dat1, dat2;
int res[7];
vector<string> ans;

bool judge() {
    for(int i = 0; i < dat1.size(); ++i) if(0 == res[dat1[i]]) return false;
    for(int i = 0; i < dat2.size(); ++i) if(1 == res[dat2[i]]) return false;
    return true;
}

void dfs(int cur, int dep, int val) {
    if(cur >= dep) {
	res[0] = res[6];
        if(judge()) {
            string str;
            for(int i = 1; i <= N; ++i) str += res[i%6] + '0';
            ans.push_back(str);
        }
    	return;
    }
    for(int i = 1; i <= 4; ++i) if(!(val & (1 << i))){
        if(1 == i) {
            for(int j = 1; j < 7; ++j) res[j] = !res[j];
            dfs(cur + 1, dep, val + (1 << i));
            for(int j = 1; j < 7; ++j) res[j] = !res[j];
        }
        else if(2 == i) {
            for(int j = 1; j < 7; j += 2) res[j] = !res[j];
            dfs(cur + 1, dep, val + (1 << i));
            for(int j = 1; j < 7; j += 2) res[j] = !res[j];
        }
        else if(3 == i) {
            for(int j = 2; j < 7; j += 2) res[j] = !res[j];
            dfs(cur + 1, dep, val + (1 << i));
            for(int j = 2; j < 7; j += 2) res[j] = !res[j];
        }
        else if(4 == i) {
            for(int j = 1; j < 7; j += 3) res[j] = !res[j];
            dfs(cur + 1, dep, val + (1 << i));
            for(int j = 1; j < 7; j += 3) res[j] = !res[j];
        }
    }
}

int main() {
    scanf("%d %d", &N, &C);

    if(0 != C) {
        while(C > 4) C -= 2;
    }

    int a;
    while(scanf("%d", &a) && -1 != a) dat1.push_back(a%6);
    while(scanf("%d", &a) && -1 != a) dat2.push_back(a%6);
    
    for(int i = 1; i < 7; ++i) res[i] = 1;
    if(2 == C) {
        dfs(0, 0, 0);
        dfs(0, 2, 0);
    }
    else if(3 == C) {
        dfs(0, 1, 0);
        dfs(0, 3, 0);
    }
    else if(4 == C) {
        dfs(0, 0, 0);
	dfs(0, 2, 0);
        dfs(0, 4, 0);
    }
    else dfs(0, C, 0);
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if(0 == ans.size()) printf("IMPOSSIBLE\n");
    else for(int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    return 0;
}
