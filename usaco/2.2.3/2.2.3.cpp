#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
int n;

bool judge(unsigned int n) {
    bool dat1[maxn], dat2[maxn];
    int dat3[maxn];
    int num = 0;
    unsigned int tmp = n;
    int sum = 0;

    memset(dat1, 0, sizeof(dat1));
    while(tmp) {
        if(tmp % 10 == 0) return false;
        //ans += tmp % 10;
        if(dat1[tmp % 10]) return false;
        dat1[tmp % 10] = 1;
        dat3[num++] = tmp % 10;
        sum += tmp % 10;
        tmp /= 10;
    }

    if(sum % num != 0) return false;
    sum = 1;
    memset(dat2, 0, sizeof(dat2));
    for(int i = num - 1; i >= 0; --i) {
	 sum += dat3[num - sum]; 
         sum %= num; 
         if(0 == sum) sum = num; 
	 if(dat2[sum]) return false;
         else dat2[sum] = 1;
    }
    return true;
}

int main() {
    scanf("%d", &n);
	
    if(n < 10) { printf("%d\n", n); return 0; }
    for(unsigned int i = n + 1; ; ++i) {
        if(judge(i)) { printf("%d\n", i); break; }
    }
    return 0;
}
