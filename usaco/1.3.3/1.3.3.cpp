#include <bits/stdc++.h>

using namespace std;

#define f(i, n) for(int i = 0; i < n; ++i)

int n;
vector<int> vc;

bool isNum(int x) {
    set<int> st;
    f(i, n) st.insert(vc[i]);
    while(x) {
        int tmp = x % 10;
        if(st.count(tmp) == 0) return false;
        x /= 10;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int a;
    f(i, n) scanf("%d", &a), vc.push_back(a);
    
    int ans = 0;
    f(i, n) f(j, n) f(k, n) f(l, n) f(t, n) {
	    int tmp1 = vc[i] * 100 + vc[j] * 10 + vc[k];
	    int tmp2 = tmp1 * vc[l] * 10;
	    int tmp3 = tmp1 * vc[t];
	    if(tmp2 >= 1000 && tmp2 < 10000 && 
	       tmp3 >= 100 && tmp3 < 1000 && 
	       tmp2 + tmp3 >= 1000 && tmp2 + tmp3 < 10000 && 
           isNum(tmp2/10) && isNum(tmp3) && isNum(tmp2 + tmp3)) ans++;

    }

    printf("%d\n", ans);
    return 0;
}
