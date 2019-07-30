#include <bits/stdc++.h>

using namespace std;

#define Rep(i, s, e) for(int i = s; i < e; ++i)

const int maxn = 1e3 + 10;
int dat1[maxn], dat2[maxn], n, num[4];

int main() {
    scanf("%d", &n);

    Rep(i, 0, n) scanf("%d", &dat1[i]), dat2[i] = dat1[i], num[dat1[i]]++;

    sort(dat2, dat2 + n);
    
    int ans = 0;
    Rep(i, 0, num[1]) if(dat1[i] != dat2[i]) {
        if(2 == dat1[i]) {
            bool flags = false;
            Rep(j, num[1], num[1] + num[2]) if(1 == dat1[j]) { swap(dat1[i], dat1[j]), flags = true; break; }
            if(!flags) Rep(j, num[1] + num[2], n) if(1 == dat1[j]) { swap(dat1[i], dat1[j]), flags = true; break; }
            if(flags) ans++;
        }   
        else if(3 == dat1[i]) {
            bool flags = false;
            Rep(j, num[1] + num[2], n) if(1 == dat1[j]) { swap(dat1[i], dat1[j]), flags = true; break; }
            if(!flags) Rep(j, num[1], num[1] + num[2]) if(1 == dat1[j]) { swap(dat1[i], dat1[j]), flags = true; break; }
            if(flags) ans++;
        }
    }
    Rep(i, num[1], num[1] + num[2]) if(dat1[i] != dat2[i]) ans++;
    printf("%d\n", ans);
    return 0;
}

