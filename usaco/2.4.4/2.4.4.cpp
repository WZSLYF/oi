#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;
const int INF = 1e6;
int dat[maxn][maxn];
bool isVis[maxn];
int P;

int calc(char ch) {
    if(ch >= 'a' && ch <= 'z') return ch - 'a';
    return ch - 'A' + 26;
}

int main() {
    scanf("%d", &P);
    
    for(int i = 0; i < maxn; ++i) {
        for(int j = 0; j < maxn; ++j) dat[i][j] = INF;
    }
    
    //char ch = getchar();
    //while(ch != '\n') ch = getchar();
    for(int i = 0; i < P; ++i) {
        char ch1, ch2;
        int val;
        scanf("\n%c %c %d", &ch1, &ch2, &val);
        //printf("%c %c %d\n", ch1, ch2, val);
        int a = calc(ch1), b = calc(ch2);
        dat[a][b] = min(dat[a][b], val);
        dat[b][a] = min(dat[b][a], val);
	//ch = getchar();
    	//while(ch != '\n') ch = getchar();
    }

    for(int k = 0; k < maxn; ++k) {
        for(int i = 0; i < maxn; ++i) {
            for(int j = 0; j < maxn; ++j) if(dat[i][j] > dat[i][k] + dat[k][j]) dat[i][j] = dat[i][k] + dat[k][j];
        }
    }
    
    int Min = INF, ind = 0;
    for(int i = 26; i < maxn; ++i) if(i != 51 && dat[51][i] < Min) Min = dat[51][i], ind = i;

    printf("%c %d\n", ind- 26 + 'A', Min);
    return 0;
}
