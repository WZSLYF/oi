#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
char str[maxn];
int dat[maxn][maxn];
bool isVis[maxn][maxn][maxn][maxn][4][4];
const int X[] = {-1, 0, 1, 0};
const int Y[] = {0, 1, 0, -1};
struct node {
    int x, y, ind;
}S, E;

void dfs(node& s, node& e, int& val)
{
    if(s.x == e.x && s.y == e.y)
    {
        return;
    }
    if(isVis[s.x][s.y][e.x][e.y][s.ind][e.ind])
    {
        val = 0;
        return;
    }
    
    isVis[s.x][s.y][e.x][e.y][s.ind][e.ind] = 1;
    if(dat[s.x + X[s.ind]][s.y + Y[s.ind]]) {
        s.x += X[s.ind], s.y += Y[s.ind];
    }
    else
    {
        s.ind++;
        s.ind %= 4;
    }

    if(dat[e.x + X[e.ind]][e.y + Y[e.ind]]) {
        e.x += X[e.ind], e.y += Y[e.ind];
    }
    else {
        e.ind++;
        e.ind %= 4;
    }
    val++;
    dfs(s, e, val);
}

int main() {
    for(int i = 1; i <= 10; ++i) {
        scanf("%s", str + 1);
        for(int j = 1; j <= 10; ++j) {
            if(str[j] == '.') dat[i][j] = 1;
            else if(str[j] == 'F') S.x = i, S.y = j, S.ind = 0, dat[i][j] = 1;
            else if(str[j] == 'C') E.x = i, E.y = j, E.ind = 0, dat[i][j] = 1;
        }
    }
    
    int res = 0;
    dfs(S, E, res);
    printf("%d\n", res);
    return 0;
}
