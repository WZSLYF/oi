/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.3.3.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Fri 18 Jun 2021 11:17:11 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10400;
const int maxc = 26;
const int maxr = 40;
int cost[maxc][maxr], kingcost[maxc][maxr], kdist[maxc][maxr], dis[maxc][maxr][2];
int nrow, ncol;

int do_step(int x, int y, int kflag) {
    int f = 0;
    int d = dis[x][y][kflag];

    if(y > 0) {
        if(x > 1) {
            if(dis[x - 2][y - 1][kflag] > d + 1) {
                dis[x - 2][y - 1][kflag] = d + 1;
                f = 1;
            }
        }
        if(x < ncol - 2) {
            if(dis[x + 2][y - 1][kflag] > d + 1) {
                dis[x + 2][y - 1][kflag] = d + 1;
                f = 1;
            }
        }
        if(y > 1) {
            if(x > 0) {
                if(dis[x - 1][y - 2][kflag] > d + 1) {
                    dis[x - 1][y - 2][kflag] = d + 1;
                    f = 1;
                }
            }
            if(x < ncol - 1) {
                if(dis[x + 1][y - 2][kflag] > d + 1) {
                    dis[x + 1][y - 2][kflag] = d + 1;
                    f = 1;
                }
            }
        }
    }
    
    if(y < nrow - 1) {
        if(x > 1) {
            if(dis[x - 2][y + 1][kflag] > d + 1) {
                dis[x - 2][y + 1][kflag] = d + 1;
                f = 1;
            }
        }
        if(x < ncol - 2) {
            if(dis[x + 2][y + 1][kflag] > d + 1) {
                dis[x + 2][y + 1][kflag] = d + 1;
                f = 1;
            } 
        }
        if(y < nrow - 2) {
            if(x > 0) {
                if(dis[x - 1][y + 2][kflag] > d + 1) {
                    dis[x - 1][y + 2][kflag] = d + 1;
                    f = 1;
                }
            }
            if(x < ncol - 1) {
                if(dis[x + 1][y + 2][kflag] > d + 1) {
                    dis[x + 1][y + 2][kflag] = d + 1;
                    f = 1;
                }
            }
        }
    }

    if(kflag == 0 && dis[x][y][1] > d + kdist[x][y]) {
        dis[x][y][1] = d + kdist[x][y];
        if(kdist[x][y] > f) f = kdist[x][y];
    }

    return f;
}

void calc(int col, int row) {
    int i, j;
    int d;
    int Max;
    int f;

    for(i = 0; i < ncol; ++i) {
        for(j = 0; j < nrow; ++j) dis[i][j][0] = dis[i][j][1] = maxn;
    }

    dis[col][row][0] = 0;
    Max = dis[col][row][1] = kdist[col][row];

    for(d = 0; d <= Max; ++d) {
        for(i = 0; i < ncol; ++i) {
            for(j = 0; j < nrow; ++j) {
                if(dis[i][j][0] == d) {
                    f = do_step(i, j, 0);
                    if(d + f > Max) Max = d + f;
                }
                if(dis[i][j][1] == d) {
                    f = do_step(i, j, 1);
                    if(d + f > Max) Max = d + f;
                }
            }
        }
    }
}

int main()
{
#ifdef Debug
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
#endif
    scanf("%d %d", &nrow, &ncol);
    char t[10];
    int pr, pc;
    scanf("%s %d", t, &pr);
    pc = t[0] - 'A';
    pr--;

    int i, j;
    for(i = 0; i < ncol; ++i) {
        for(j = 0; j < nrow; ++j) {
            int tmp1 = abs(pc - i);
            int tmp2 = abs(pr - j);
            if(tmp1 < tmp2) tmp1 = tmp2;
            kingcost[i][j] = kdist[i][j] = tmp1;
        }
    }

    while(scanf("%s %d", t, &pr) == 2) {
        pc = t[0] - 'A';
        pr--;
        
        calc(pc, pr);

        for(i = 0; i < ncol; ++i) {
            for(j = 0; j < nrow; ++j) {

                cost[i][j] += dis[i][j][0];

                if(dis[i][j][1] - dis[i][j][0] < kingcost[i][j]) {
                    kingcost[i][j] = dis[i][j][1] - dis[i][j][0];
                }
            }
        }
    }

    pc = cost[0][0] + kingcost[0][0];
    for(i = 0; i < ncol; ++i) {
        for(j = 0; j < nrow; ++j) pc = min(pc, cost[i][j] + kingcost[i][j]);
    }
    printf("%d\n", pc);
    return 0;
}

