#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
const int maxn = 1e5 + 10;
int dat[maxn], N, D, num, ind;
string str;

void solve(int n, int d) {
    str += std::to_string(n / d);
    str += ".";
    int size = str.size();
    int tmp = n % d;
    if(!tmp) str += "0";
    else {
        //str += ".";
        while(tmp) {
	        if(!dat[tmp]) dat[tmp] = num++;
            else {
                //printf("%d %d\n", num, dat[val]);
                ind = dat[tmp];
                break;
            }
            tmp *= 10;
            int val = tmp / d;
	        str += val + '0';
            tmp = tmp % d;
        }
    }

    if(ind != -1) {
        //printf("%d\n", ind);
        str.insert(size + ind - 1, "(");
        str += ")";
    }

    for(int i = 0; i < str.size(); ++i) {
        if(i && (i % 76 == 0)) printf("\n");
        printf("%c", str[i]);
    }
    if(str.size() % 76) printf("\n");
}

int main() {
    scanf("%d %d", &N, &D);
    
    str.clear();
    num = 1;
    ind = -1;
    solve(N, D);
    return 0;
}
