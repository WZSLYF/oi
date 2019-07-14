#include <bits/stdc++.h>

using namespace std;

const int maxn = 150000;
int N, M;
bool isNum[maxn];
int dat[maxn];
struct A {
    int S, V;
    inline bool operator < (const A& b) const {
        if(V == b.V) return S < b.S;
        return V < b.V;
    }
};
vector<A> ans;
set<int> st;

void init() {
    for(int i = 0; i <= M; ++i) {
        for(int j = i; j <= M; ++j) st.insert(i*i + j*j), isNum[i*i+j*j] = 1;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    init();
    
    int n = 0;
    for(set<int>::iterator iter = st.begin(); iter != st.end(); ++iter) dat[n++] = *iter;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int tmp = dat[j] - dat[i];
            int flags = -1;
            for(int k = 2; k < N; ++k) { if(dat[i] + tmp * k > 2*M*M ) { flags = 0; break; }
	    if(!isNum[dat[i] + tmp * k]) {flags = 1; break;} }
            if(1 == flags) continue;
	    if(0 == flags) break;
            A b;
            b.S= dat[i], b.V = tmp;
            ans.push_back(b);
        }
    }

    if(0 == ans.size()) printf("NONE\n");
    else {
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].S, ans[i].V);
    }
    return 0;
}
