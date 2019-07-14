#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 15;
char str1[maxn][maxn], str2[maxn][maxn], str3[maxn][maxn];
int n;

void init() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) str3[i][j] = str1[i][j];
    }
}

void rot() {
    char strtmp[maxn][maxn];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) strtmp[j][n - i + 1] = str3[i][j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) str3[i][j] = strtmp[i][j];
    }
}

void flip() {
    char strtmp[maxn][maxn];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) strtmp[i][n - i + 1] = str3[i][j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) str3[i][j] = strtmp[i][j];
    }
}

bool iseq() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) if(str2[i][j] != str3[i][j]) return false;
    }
    return true;
}

void print();

int solve() {
    init();
    //print();
    rot();
    //print();
    if(iseq()) return 1;

    rot();
    if(iseq()) return 2;

    rot();
    if(iseq()) return 3;

    init();
    flip();
    if(iseq()) return 4;

    rot();
    if(iseq()) return 5;

    rot();
    if(iseq()) return 5;

    rot();
    if(iseq()) return 5;

    init();
    if(iseq()) return 6;

    return 7;
}

void print() {
    for(int i = 1; i <= n; ++i) {
        printf("%s\n", str3[i] + 1);
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%s", str1[i] + 1);
    for(int i = 1; i <= n; ++i) scanf("%s", str2[i] + 1);
    
    //for(int i = 1; i <= n; ++i) printf("%s\n", str1[i] + 1);
    printf("%d\n", solve());
   return 0;
}

